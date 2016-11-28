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

int simulateMemoryFIFO(DArray &pageNumbers, int frameSize, float& fifo2000, float& fifo4000, float& fifo6000, float& fifo8000, float& fifo10000)
{
    DArray frame(frameSize, false);  //creates a frame of frameSize size
    int pageFaults = 0;
    for(int i = 0; i < pageNumbers.size; ++i)
    {
        switch(i)
        {
            case 2000:
            {
                fifo2000 = (float)pageFaults / 2000.0;
                break;
            }
            case 4000:
            {
                fifo4000 = (float)pageFaults / 4000;
                break;
            }
            case 6000:
            {
                fifo6000 = (float)pageFaults / 6000;
                break;
            }
            case 8000:
            {
                fifo8000 = (float)pageFaults / 8000;
                break;
            }
        }
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
    fifo10000 = (float)pageFaults / 10000;
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
    int pageFaults = 0;
    
    DArray frame(frameSize, false);  //creates a frame of frameSize size
    
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
                frame.optimalReplace(pageNumbers.arr[i].number, i, pageNumbers);
            }
        }
    }
    
    
    
    
    
    return pageFaults;
}



int writeToFile(string outputFileName, int frameSize, int fifoTotal, float fifo2000, float fifo4000, float fifo6000, float fifo8000, float fifo10000, int lruTotal, float lru2000, float lru4000, float lru6000, float lru8000, float lru10000, int mfuTotal, float mfu2000, float mfu4000, float mfu6000, float mfu8000, float mfu10000, int optimalTotal, float optimal2000, float optimal4000, float optimal6000, float optimal8000, float optimal10000)
{
    ofstream outFile(outputFileName);
    if(!outFile)
    {
        return -1;
    }
    
    outFile << setw(30) << "=======================================================================" << endl;
    outFile << setw(60) << "Page Replacement Algorithm Simulation (frame size = " << frameSize <<")" << endl;
    outFile << setw(30) << "=======================================================================" << endl;
    outFile << setw(62) << "Page Fault Rates" << endl << endl;
    outFile << "Algorithm" << setw(21) << "Total Page Faults" << setw(10) << "2000" << setw(10) << "4000" << setw(10) << "6000" << setw(8) << "10000" << endl;
    outFile << setw(30) << "-----------------------------------------------------------------------" << endl;
    outFile << " FIFO" << setw(18) << fifoTotal << setw(17) << fifo2000 << setw(10) << fifo4000 << setw(10) << fifo6000
            << setw(8) << fifo10000 << endl;
    outFile << " LRU" << setw(19) << lruTotal << setw(17) << lru2000 << setw(10) << lru4000 << setw(10) << lru6000
            << setw(8) << lru10000 << endl;
    outFile << " MFU" << setw(19) << mfuTotal << setw(17) << mfu2000 << setw(10) << mfu4000 << setw(10) << mfu6000
            << setw(8) << mfu10000 << endl;
    outFile << " Optimal" << setw(15) << optimalTotal << setw(17) << optimal2000 << setw(10) << optimal4000 << setw(10) << optimal6000
            << setw(8) << optimal10000 << endl;
    
    
    outFile.close();
    return 0;
}



















