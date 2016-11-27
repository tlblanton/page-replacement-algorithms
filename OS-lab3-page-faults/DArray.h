//
//  DArray.hpp
//  OS-lab3-page-faults
//
//  Created by Tyler Blanton on 11/25/16.
//  Copyright © 2016 Tyler Blanton. All rights reserved.
//

#ifndef DArray_h
#define DArray_h

#include <iostream>
#include "Page.h"
using namespace std;


class DArray
{
public:
    Page *arr;
    int capactiy;
    int size;
    
    DArray();
    
    DArray(int customCapacity, bool populateWithZero);
    
    void resize();
    
    void print();
    
    void insert(int newInt);
    
    int readIn(string fileName);
    
    bool exists(int checkFor);
    
    int subscript(int checkFor);
    
    void fifoReplace(int newPageNumber);
    
    void lruReplace(int newPageNumber);
    
    void mfuReplace(int newPageNumber, DArray& freqArray);
    
    void optimalReplace(int newPageNumber);
};

#endif /* DArray_h */






