//
//  main.cpp
//  OS-lab3-page-faults
//
//  Created by Tyler Blanton on 11/25/16.
//  Copyright © 2016 Tyler Blanton. All rights reserved.
//

//-----------TODO: Make MFU work like FIFO when there are multiple items who have the same frequency in the pagenumber list

#include <iostream>
#include "functions.h"
#include "DArray.h"
using namespace std;

int main(int argc, const char * argv[]) {
    int frameSize;
    int fifoPageFaults, lruPageFaults, mfuPageFaults, optimalPageFaults;
    float fifo2000, fifo40000, fifo6000, fifo8000, fifo10000, lru2000, lru4000, lru6000, lru8000, lru10000, mfu2000, mfu4000, mfu6000, mfu8000, mfu10000, optimal2000, optimal4000, optimal6000, optimal8000, optimal10000;
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
    
    
    fifoPageFaults = simulateMemoryFIFO(pageNumbers, frameSize, fifo2000, fifo40000, fifo6000, fifo8000, fifo10000);
    lruPageFaults = simulateMemoryLRU(pageNumbers, frameSize, lru2000, lru4000, lru6000, lru8000, lru10000);
    mfuPageFaults = simulateMemoryMFU(pageNumbers, frameSize, mfu2000, mfu4000, mfu6000, mfu8000, mfu10000);
    optimalPageFaults = simulateMemoryOptimal(pageNumbers, frameSize, optimal2000, optimal4000, optimal6000, optimal8000, optimal10000);
    
    
    //writing to output file.
    if(writeToFile(outputFile, frameSize, fifoPageFaults, fifo2000, fifo40000, fifo6000, fifo8000, fifo10000, lruPageFaults, lru2000, lru4000, lru6000, lru8000, lru10000, mfuPageFaults, mfu2000, mfu4000, mfu6000, mfu8000, mfu10000, optimalPageFaults, optimal2000, optimal4000, optimal6000, optimal8000, optimal10000) == -1)
    {
        cerr << "Could not write to specified output file. Results not reported. " << endl;
    }
}
