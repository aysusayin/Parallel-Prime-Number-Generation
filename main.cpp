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


int primeNumberGenerator(vector<int> prime, int t, int M){
    int j ;
    int k ;
    int n ;
    int quo,rem ;
    prime.push_back(2);
    n = 3 ;
    for(j = 1; n < M; j++){// P2
        prime.push_back(n);
        bool check = true;
        while(check){//p4
            n+=2;
            k = 1;
            while(true){//p6
                quo = n / prime.at(k) ;
                rem = n % prime.at(k) ;
                if (rem == 0) {
                    break;
                }
                if (quo <= prime.at(k)){
                    check = false;
                    break;
                }
                k++;
            }
        } 
    }
    
    for(j=0; j < prime.size(); j++){ printf("%d\n", prime.at(j));}
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
    vector<int> prime;
    primeNumberGenerator(prime, 1, M);
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
