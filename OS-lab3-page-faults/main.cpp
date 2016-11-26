//
//  main.cpp
//  OS-lab3-page-faults
//
//  Created by Tyler Blanton on 11/25/16.
//  Copyright © 2016 Tyler Blanton. All rights reserved.
//

#include <iostream>
using namespace std;
#include "dArray.h"

int main(int argc, const char * argv[]) {
    int frameSize;
    string inputFile, outputFile;
    DArray pageNumbers;
    
    if(argc < 4)
    {
        cerr << "Insufficient command line arguments. Program Terminated." <<endl;
        return -1;
    }
    frameSize = atoi(argv[1]);
    inputFile = argv[2];
    outputFile = argv[3];
    
    pageNumbers.readIn(inputFile);
    
    
    
}
