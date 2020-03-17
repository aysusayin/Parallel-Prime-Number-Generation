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


int primeNumberGenerator(int* primeNumbers, int t){
    int prime[t][M];
    int j ;
    int k ;
    int n ;
    int quo,rem ;
    prime[t][0] = 2;
    n=3;
    for(j=0; j < M; j++){
        prime[t][j] = n;
        for(;rem > 0; n=n+2){
            for(k=1; quo > prime[t][k]; k++){
                quo = n / prime[t][k];
                rem = n % prime[t][k];  
            }
            
        }

    }
    return primeNumbers[t];
}


int main(int argc, char *argv[]) { 
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