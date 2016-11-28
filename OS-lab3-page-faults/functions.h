//
//  functions.h
//  OS-lab3-page-faults
//
//  Created by Tyler Blanton on 11/25/16.
//  Copyright © 2016 Tyler Blanton. All rights reserved.
//

#ifndef functions_h
#define functions_h

#include <iostream>
using namespace std;
#include <stdio.h>
#include "DArray.h"

int simulateMemoryFIFO(DArray &pageNumbers, int frameSize, float& fifo2000, float& fifo4000, float& fifo6000, float& fifo8000, float& fifo10000);
int simulateMemoryLRU(DArray &pageNumbers, int frameSize, float& lru2000, float& lru4000, float& lru6000, float& lru8000, float& lru10000);
int simulateMemoryMFU(DArray &pageNumbers, int frameSize, float& mfu2000, float& mfu4000, float& mfu6000, float& mfu8000, float& mfu10000);
int simulateMemoryOptimal(DArray &pageNumbers, int frameSize, float& optimal2000, float& optimal4000, float& optimal6000, float& optimal8000, float& optimal10000);

int writeToFile(string outputFileName, int frameSize, int fifoTotal, float fifo2000, float fifo4000, float fifo6000, float fifo8000, float fifo10000, int lruTotal, float lru2000, float lru4000, float lru6000, float lru8000, float lru10000, int mfuTotal, float mfu2000, float mfu4000, float mfu6000, float mfu8000, float mfu10000, int optimalTotal, float optimal2000, float optimal4000, float optimal6000, float optimal8000, float optimal10000);


#endif /* functions_h */
