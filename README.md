# Parallel-Processing
## CMPE 478: Parallel Processing HW 1
### Generating Prime Numbers
We needed to parallelized given prime number generator algotihm using OpenMP.

#### Prime Number Generator
To generate prime numbers first make the project by running following commands: 

```
cmake ../Parallel-Processing/
make
```
or 

```
g++ --openmp -o prime main.cpp
```


Then run the program like this:

```
./prime [Scheduling Type] [Chunk Size] [M] [Thread Num] [--print]
```

Scheduling type can be "STATIC", "DYNAMIC", "GUIDED" or "AUTO". When the scheduling type is "AUTO", chunk size is not important
but please put there a number so that program runs without any errors. 

If you want to see the prime numbers that are generated, put --print option in the end. 

#### Performance Analysis
To see the analysis, run `./primeAnalysis.sh`. You can run this file without making the project since it makes it.
 
 NOTE: "primeAnalysis.sh" program generates a file named "PrimeNumberGeneratorAnalysis.csv". So
 please be careful if you have a file with the same name since the program overwrites it.
 
There is an example csv file that contains the results generated on my computer called "ExampleAnalysis.csv".

My CPU information:
```
Architecture:        x86_64
CPU op-mode(s):      32-bit, 64-bit
Byte Order:          Little Endian
CPU(s):              4
On-line CPU(s) list: 0-3
Thread(s) per core:  2
Core(s) per socket:  2
Socket(s):           1
NUMA node(s):        1
Vendor ID:           GenuineIntel
CPU family:          6
Model:               78
Model name:          Intel(R) Core(TM) i7-6500U CPU @ 2.50GHz
Stepping:            3
CPU MHz:             3059.423
CPU max MHz:         3100.0000
CPU min MHz:         400.0000
BogoMIPS:            5184.00
Virtualization:      VT-x
L1d cache:           32K
L1i cache:           32K
L2 cache:            256K
L3 cache:            4096K
NUMA node0 CPU(s):   0-3
```
