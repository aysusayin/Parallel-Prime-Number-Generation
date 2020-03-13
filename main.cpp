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