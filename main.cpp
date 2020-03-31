#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <omp.h>

using namespace std;

static string schedulingMethod;
static int chunkSize;
static int M;
static int executionTime;
static int t;

// Calculates primes between [start, end]
int primeNumberGenerator(vector<int> &primesIn, vector<int> &primesOut, int start, int end) {
    int realStart = start;
    if (start <= 2) {
        primesOut.push_back(2);
        realStart = 1;
    } else if (start % 2 == 0) {
        realStart -= 1;
    } else {
        realStart -= 2;
    }
    int j;
    int k;
    int n;
    int quo, rem;
    n = realStart;

    for (j = 1; n <= end; j++) {// P2
        if (j != 1) primesOut.push_back(n);
        bool check = true;
        while (check) {//p4
            n += 2;
            for (k = 1; k < primesIn.size(); k++) {//p6
                quo = n / primesIn.at(k);
                rem = n % primesIn.at(k);
                if (rem == 0) {
                    break;
                }
                if (quo <= primesIn.at(k)) {
                    check = false;
                    break;
                }
            }
            if (k >= primesIn.size()) check = false;
        }

    }
}

// Calculates prime numbers up to end.
int primeNumberGenerator(vector<int> &primes, int end) {
    primeNumberGenerator(primes, primes, 1, end);
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        cout << "All arguments are required: Scheduling method, chunk size, M, number of threads.";
        return 0;
    }
    schedulingMethod = argv[1];
    transform(schedulingMethod.begin(), schedulingMethod.end(), schedulingMethod.begin(), ::toupper);
    chunkSize = stoi(argv[2]);
    M = stoi(argv[3]);
    t = stoi(argv[4]);

    vector<int> prime;
    vector<int> primeOut;
    int squareRootM = (int) sqrt(M);
    primeNumberGenerator(prime, squareRootM);

    omp_set_num_threads(t);
    if (schedulingMethod.compare("STATIC")) {
        omp_set_schedule(omp_sched_static, chunkSize);
    } else if (schedulingMethod.compare("DYNAMIC")) {
        omp_set_schedule(omp_sched_dynamic, chunkSize);
    } else if (schedulingMethod.compare("GUIDED")) {
        omp_set_schedule(omp_sched_guided, chunkSize);
    } else if (schedulingMethod.compare("AUTO")) {
        omp_set_schedule(omp_sched_auto, chunkSize);
    }

    int tid;
    vector<vector<int>> threads_prime;
    #pragma omp parallel private(tid) shared(threads_prime, M, squareRootM, prime)
    {
        tid = omp_get_thread_num();
        printf("tid %d\n", tid);
        vector<int> primesOut;

        #pragma omp for schedule(runtime) nowait
        for (int i = squareRootM + 1; i <= M; i += 2) {
            primeNumberGenerator(prime, primesOut, i, i + 1);
        }
        #pragma omp critical
        threads_prime.push_back(primesOut);
    }

    for (auto tmp : threads_prime) {
        for (int j : tmp) {
            prime.push_back(j);
        }
    }
    sort(prime.begin(), prime.end());

    for (int j : prime)
        printf("%d\n", j);

    return 0;
}
