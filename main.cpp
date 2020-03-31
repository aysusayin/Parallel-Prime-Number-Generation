#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <list>
#include <sstream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <omp.h>

using namespace std;

static string schedulingMethod;
static int chunkSize;
static int M;
static int executionTime;

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
    if (argc < 4) {
        cout << "All arguments are required";
        return 0;
    }
    schedulingMethod = argv[1];
    transform(schedulingMethod.begin(), schedulingMethod.end(), schedulingMethod.begin(), ::toupper);
    chunkSize = stoi(argv[2]);
    M = stoi(argv[3]);
    vector<int> prime;
    vector<int> primeOut;
    int squareRootM = (int) sqrt(M);
    primeNumberGenerator(prime, squareRootM);


    if (schedulingMethod.compare("STATIC")) {
        cout << schedulingMethod;
    } else if (schedulingMethod.compare("DYNAMIC")) {
        cout << schedulingMethod;
    } else if (schedulingMethod.compare("GUIDED_A")) {
        cout << schedulingMethod;
    } else if (schedulingMethod.compare("GUIDED_B")) {
        cout << schedulingMethod;
    }

    int tid;
    vector<vector<int>> threads_prime;
#pragma omp parallel private(tid) shared(threads_prime, M, squareRootM, prime, chunkSize)
    {
        tid = omp_get_thread_num();
        vector<int> primesOut;

#pragma omp for schedule(static, chunkSize)
        for (int i = squareRootM + 1; i <= M; i += 2) {
            primeNumberGenerator(prime, primesOut, i, i + 1);
        }
#pragma omp critical
        threads_prime.push_back(primesOut);

    }
    for(int i=0; i<threads_prime.size();i++){
        vector<int> tmp=threads_prime.at(i);
        for(int j=0; j<tmp.size();j++)
            printf("%d\n", tmp.at(j));
    }
    return 0;
}
