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


int primeNumberGenerator(int prime[N]){ // t is the no of threads
    
    int j ;
    int k ;
    int n ;
    int quo,rem ;
    prime[0] = 2 ;
    n = 3 ;
    j = 1 ;
    prime[0] = 2;
    for(; j < prime.length(); j++){// P2
        prime[j] = n;
        bool check = True;
        for(; check; n+=2){//p4
            k = 1;
            for (; True; ){//p6
                quo = n / prime[k] ;
                rem = n % prime[k] ;
                if (rem == 0) {
                    break
                } ;
                if (quo <= prime[k]){
                    check = False;
                    break
                }
                k++;
            }
        } 
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
