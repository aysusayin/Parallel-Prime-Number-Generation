#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <list>
#include <sstream>
#include <algorithm>
#include <queue>

using namespace std;

/*
$ sudo g++ hello.cpp (or)

$ sudo g++ -o hello hello.cpp

$ ./a.out (If you compiled using first command)

Or

$ ./hello (If you compiled using second command)
*/

static string schedulingMethod;
static int chunkSize;
static int M;
static int executionTime;


int primeNumberGenerator(int* primeNumbers, int t){ // t is the no of threads
    int prime[t][M];
    int j = 1;
    int k ;
    int n = 3;
    int quo;
    int rem;
    prime[t][0] = 2;
    for(; j < M; j++){
        prime[t][j] = n;
        do{
            n = n + 2;
            k=1;
            do{
                quo = n / prime[t][k];
                rem = n % prime[t][k];
                if(rem == 0) break;
                if(quo <= prime[t][k]) break;
                k++;
            }while(true);
            if(quo <= prime[t][k]) break;
        }while(true);
    }
    prime[t][j] = n;
    
    for(j=0; j < M; j++){ printf("%d\n", prime[t][j]);}
}


int main(int argc, char *argv[]) {
    int* p=0;
    M = 20;
    primeNumberGenerator(p, 1);
    return 0;
    if(argc < 4){
        cout << "All arguments are required";
        return 0;
    }   
    schedulingMethod = argv[1];
    transform(schedulingMethod.begin(), schedulingMethod.end(), schedulingMethod.begin(), ::toupper);
    chunkSize = stoi(argv[2]);
    M = stoi(argv[3]);

    if(schedulingMethod.compare("STATIC")){
        cout << schedulingMethod;
    }
    else if (schedulingMethod.compare("DYNAMIC")){
        cout << schedulingMethod;
    }
    else if (schedulingMethod.compare("GUIDED_A")){
        cout << schedulingMethod;
    }
    else if (schedulingMethod.compare("GUIDED_B")){
        cout << schedulingMethod;
    }


    return 0;
}
