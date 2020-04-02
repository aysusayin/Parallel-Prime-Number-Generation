#!/usr/bin/env bash

echo "WARNING:Must have 4 CPUs at least"

g++ --openmp -o prime main.cpp

echo "Program compiled"

lines=('M,OpenMp Loop Scheduling Method,Chunk Size,T1,T2,T4,S2,S4')

for M in 1000000 10000000 50000000 80000000; do
  for sched_type in "STATIC" "DYNAMIC" "GUIDED" "AUTO"; do
    for chunk in 1 10 100; do
      if [[ $sched_type != "AUTO" ]] || [[ $chunk -eq 1 ]]; then
        declare -A exec_times
        for t in 1 2 4; do
          exec_time="$(grep -oP "Execution time:\s+\K\d+" <<<"$(./prime $sched_type $chunk $M $t)")"
          exec_times[$t]=${exec_time}
        done
        s2=$(bc <<<"scale=3; ${exec_times[1]} / ${exec_times[2]}")
        s4=$(bc <<<"scale=3; ${exec_times[1]} / ${exec_times[4]}")
        line="$M,$sched_type,$chunk,${exec_times[1]},${exec_times[2]},${exec_times[4]},$s2,$s4"
        lines+=("${line}")
      fi
    done
    echo "Analysis for $M $sched_type is done"
  done
done

file_name="PrimeNumberGeneratorAnalysis.csv"

rm -f ${file_name}

for line in "${lines[@]}"; do
  echo "$line" >>"$file_name"
done

echo "Done!"
