//
//  dArray.cpp
//  OS-lab3-page-faults
//
//  Created by Tyler Blanton on 11/25/16.
//  Copyright © 2016 Tyler Blanton. All rights reserved.
//

#include <fstream>
#include "DArray.h"
#include "Page.h"
using namespace std;


/*
 *  CONSTRUCTOR
 *
 */
DArray::DArray()
{
    capactiy = 10000;
    arr = new Page[capactiy];
    size = 0;
}


/*
 * CONSTRUCTOR - CUSTOM SIZE
 *
 */
DArray::DArray(int customCapacity, bool populateWithZero)
{
    capactiy = customCapacity;
    arr = new Page[capactiy];
    
    if(populateWithZero)
    {
        size = customCapacity;
        for(int i = 0; i < size; ++i)
        {
            arr[i].number = -1; //filling with arbitrary "blank" value
        }
    }
    else
    {
        size = 0;
    }
}


/*
 * RESIZE
 *
 */
void DArray::resize()
{
    int newCap = capactiy * 2;
    Page *newArr = new Page[newCap];
    
    for(int i = 0; i < size; ++i)
    {
        newArr[i].number = arr[i].number;
        newArr[i].place = arr[i].place;
    }
    
    delete []arr;
    
    arr = newArr;
    capactiy = newCap;
}


/*
 * Print
 *
 */
void DArray::print()
{
    cout << "----------------" << endl;
    for(int i = 0; i < size; ++i)
    {
        cout << arr[i].number << " : " << arr[i].place << " : "  <<  arr[i].frequency << endl;
    }
    cout << "----------------" << endl;
}


/*
 * INSERT
 *
 */
void DArray::insert(int newInt)
{
    if(size == capactiy)
    {
        resize();
    }
    
    //incrementing existing pages "place" variable
    for(int i = 0; i < size; ++i)
    {
        ++arr[i].place;
    }
    
    //creating new page. It has place of 1 because it is the newest variable in the array
    Page tempPage(newInt);
    tempPage.place = 1;
    tempPage.frequency = 0;
    
    //putting this new page in the array
    arr[size] = tempPage;
    ++size;
}


/*
 * READIN
 *
 */
int DArray::readIn(string fileName)
{
    ifstream inFile(fileName);
    if(!inFile)
    {
        return -1;
    }
    
    int temp;
    inFile >> temp;
    
    while(inFile)
    {
        insert(temp);
        inFile >> temp;
    }
    inFile.close();
    return 0;
}


/*
 * exists
 *
 */
bool DArray::exists(int checkFor)
{
    for(int i = 0; i < size; ++i)
    {
        if(arr[i].number == checkFor)
        {
            return true;
        }
    }
    return false;
}


/*
 * subscript
 * NOTE: This returns the FIRST instance of the page number being cheked for
 */
int DArray::subscript(int checkFor)
{
    for(int i = 0; i < size; ++i)
    {
        if(arr[i].number == checkFor)
        {
            return i;
        }
    }
    cerr << "Could not locate number in array." << endl;
    return -1;
}


/*
 * fifoReplace
 *
 */
void DArray::fifoReplace(int newPageNumber)
{
    
    for(int i = 1; i < size; ++i)
    {
        arr[i-1].number = arr[i].number;
        arr[i-1].place = arr[i].place;
    }
    arr[size-1].number = newPageNumber;
    arr[size-1].place = 1;
}


/*
 * lruReplace
 *
 */
void  DArray::lruReplace(int newPageNumber)
{
    //the page with the maximum number will be the one that was used LEAST RECENTLY
    int max = 0;
    for(int i = 1; i < size; ++i)
    {
        if(arr[i].place > arr[max].place)
        {
            max = i;
        }
    }
    
    for(int i = 0; i < size; ++i)
    {
        if(i != max)
        {
            ++arr[i].place;
        }
    }
    arr[max].number = newPageNumber;
    arr[max].place = 1;
}


/*
 * mfuReplace
 * NOTE: if there are multiple numbers in the list that have been used the highest number of times comparitively, then this algorithm removes the first
 * one it comes across
 */
void  DArray::mfuReplace(int newPageNumber, DArray& freqArray)
{
    int maxFreqSub = 0;
    for(int x = 1; x < size; ++x)
    {
        if(arr[x].frequency > arr[maxFreqSub].frequency)
        {
            maxFreqSub = x;
        }
    }
    
    arr[maxFreqSub].number = newPageNumber;
}


/*
 * optimalReplace
 *
 */
void  DArray::optimalReplace(int newPageNumber, int currentSpot, DArray& pageNumbers)
{
    //give each page it's distanceFromSpot variable
    DArray frameNumbersNotInList;
    bool foundInPageNumbers = false;
    bool newNumberPlaced = false;
    
    int maxDistanceSub = 0;
    
    //looping around numbers in frame
    for(int i = 0; i < size; ++i)
    {
        foundInPageNumbers = false;
        
        //looping around numbers in page ahead of our currentPosition
        for(int x = (currentSpot+1); x < pageNumbers.size; ++x)
        {
            if(arr[i].number == pageNumbers.arr[x].number)
            {
                foundInPageNumbers = true;
                arr[i].distanceFromSpot = x - currentSpot + 1; 
                
                //keeping track of which number is farthest distance away. This is the number that will be switched out.
                if(arr[i].distanceFromSpot > arr[maxDistanceSub].distanceFromSpot)
                {
                    maxDistanceSub = i;
                }
            }
        }
        if(!foundInPageNumbers)
        {
            //if the number being looked at in the frame is not in the rest of the list, then we replace it with the new one
            arr[i].number = newPageNumber;
            newNumberPlaced = true;
            break;
        }
    }
    
    if(!newNumberPlaced)
    {
        int maxDistanceSub = 0;
        for(int i = 1; i < size; ++i)
        {
            if(arr[i].distanceFromSpot > arr[maxDistanceSub].distanceFromSpot)
            {
                maxDistanceSub = i;
            }
        }
        arr[maxDistanceSub].number = newPageNumber;
    }
    //resetting all distanceFromSpot variables for next call to algorithm.
    for(int i = 0; i < size; ++i)
    {
        arr[i].distanceFromSpot = 0;
    }
}
