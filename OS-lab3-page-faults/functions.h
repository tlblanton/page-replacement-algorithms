//
//  functions.h
//  OS-lab3-page-faults
//
//  Created by Tyler Blanton on 11/25/16.
//  Copyright © 2016 Tyler Blanton. All rights reserved.
//

#ifndef functions_h
#define functions_h

#include <stdio.h>
#include "DArray.h"

int simulateMemoryFIFO(DArray &pageNumbers, int frameSize);
int simulateMemoryLRU(DArray &pageNumbers, int frameSize);
int simulateMemoryMFU(DArray &pageNumbers, int frameSize);
int simulateMemoryOptimal(DArray &pageNumbers, int frameSize);

int writeToFile(string outputFileName);


#endif /* functions_h */
