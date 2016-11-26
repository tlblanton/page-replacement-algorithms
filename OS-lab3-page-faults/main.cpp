//
//  main.cpp
//  OS-lab3-page-faults
//
//  Created by Tyler Blanton on 11/25/16.
//  Copyright © 2016 Tyler Blanton. All rights reserved.
//

// TODO: figure out how to keep track of what was put in the dynamic array when. There will be /frameSize/ places and I will have to update them all
//       accordingly each time a new thing is put into the frame



#include <iostream>
using namespace std;
#include "dArray.h"
#include "functions.h"

int main(int argc, const char * argv[]) {
    int frameSize;
    int fifoPageFaults, lruPageFaults, mfuPageFaults, optimalPageFaults;
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
    
    fifoPageFaults = simulateMemoryFIFO(pageNumbers, frameSize);
    lruPageFaults = simulateMemoryLRU(pageNumbers, frameSize);
    mfuPageFaults = simulateMemoryMFU(pageNumbers, frameSize);
    optimalPageFaults = simulateMemoryOptimal(pageNumbers, frameSize);
    
    if(writeToFile(outputFile) == -1)
    {
        cerr << "Could not open output file. Results not reported. " << endl;
    }
}
