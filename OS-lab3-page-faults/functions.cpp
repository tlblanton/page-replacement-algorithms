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
                frame.lruReplace(pageNumbers.arr[i].number);
            }
        }
        else
        {
            int tempSub = -1, tempPlace = -1;
            //find the subscript of the found item, increment the subscript of everything from 0 -> subscript, and set it's subscript to i
            for(int x = 0; x < frame.size; ++x)
            {
                if(frame.arr[x].number == pageNumbers.arr[i].number)
                {
                    tempSub = x;
                    tempPlace = frame.arr[x].place;
                    break;
                }
            }
            for(int x = 0; x < tempPlace; ++x)
            {
                ++frame.arr[x].place;
            }
            frame.arr[tempSub].place = 1;
        }
    }
    
    return pageFaults;
}

int simulateMemoryMFU(DArray &pageNumbers, int frameSize)
{
    DArray frame(frameSize, false);  //creates a frame of frameSize size
    DArray freqArray;
    int pageFaults = 0;
    
    //this FOR loop just fills freqArray properly
    for(int i = 0; i < pageNumbers.size; ++i)
    {
        if(!freqArray.exists(pageNumbers.arr[i].number))
        {
            freqArray.insert(pageNumbers.arr[i].number);
            ++freqArray.arr[freqArray.size-1].frequency;
        }
        else
        {
            //find subscript of existing item, then increment it's value
            ++freqArray.arr[freqArray.subscript(pageNumbers.arr[i].number)].frequency; //oh boy that is an ugly line of code.
        }
        
    }

    //this FOR loop is the actual MFU algorithm
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
                frame.mfuReplace(pageNumbers.arr[i].number, freqArray);
            }
        }
        
    }
    
    
    
    
    
    return pageFaults;
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



















