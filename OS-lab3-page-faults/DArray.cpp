//
//  dArray.cpp
//  OS-lab3-page-faults
//
//  Created by Tyler Blanton on 11/25/16.
//  Copyright © 2016 Tyler Blanton. All rights reserved.
//

#include <fstream>
#include "dArray.h"
using namespace std;

DArray::DArray()
{
    capactiy = 500;
    size = 0;
    arr = new int[capactiy];
}

void DArray::resize()
{
    int newCap = capactiy * 2;
    int *newArr = new int[newCap];
    
    for(int i = 0; i < size; ++i)
    {
        newArr[i] = arr[i];
    }
    
    delete []arr;
    
    arr = newArr;
    capactiy = newCap;
}

void DArray::insert(int newInt)
{
    if(size == capactiy)
    {
        resize();
    }
    arr[size] = newInt;
    ++size;
}

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













