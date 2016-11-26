//
//  functions.cpp
//  OS-lab3-page-faults
//
//  Created by Tyler Blanton on 11/25/16.
//  Copyright © 2016 Tyler Blanton. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include "functions.h"
#include "DArray.h"

using namespace std;

int simulateMemoryFIFO(DArray &pageNumbers, int frameSize)
{
    DArray frame(frameSize, false);  //creates a frame of frameSize size
    int pageFaults = 0;
    for(int i = 0; i < pageNumbers.size; ++i)
    {
        // If the page number is not in the frame then that is a page fault and we
        // need to use a replacement algorithm
        if(!frame.exists(pageNumbers.arr[i].number))
        {
            ++pageFaults;
            if(frame.size < frame.capactiy)
            {
                frame.insert(pageNumbers.arr[i].number);
            }
            else
            {
                //replacing oldest thing in frame with this page number.
                frame.fifoReplace(pageNumbers.arr[i].number);
            }
        }
    }
    return pageFaults;
}

int simulateMemoryLRU(DArray &pageNumbers, int frameSize)
{
    DArray frame(frameSize, false);  //creates a frame of frameSize size
    
    int pageFaults = 0;
    for(int i = 0; i < pageNumbers.size; ++i)
    {
        if(!frame.exists(pageNumbers.arr[i].number))
        {
            ++pageFaults;
            if(frame.size < frame.capactiy)
            {
                frame.insert(pageNumbers.arr[i].number);
            }
            else
            {
                
            }
        }
    }
    
    return -1;
}

int simulateMemoryMFU(DArray &pageNumbers, int frameSize)
{
    DArray frame(frameSize, false);  //creates a frame of frameSize size
    
    return -1;
}

int simulateMemoryOptimal(DArray &pageNumbers, int frameSize)
{
    DArray frame(frameSize, false);  //creates a frame of frameSize size
    
    return -1;
}



int writeToFile(string outputFileName)
{
    ofstream outFile(outputFileName);
    if(!outFile)
    {
        return -1;
    }
    
    
    
    
    
    
    return 0;
}



















