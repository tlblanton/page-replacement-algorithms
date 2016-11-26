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
using namespace std;


class DArray
{
public:
    int *arr;
    int capactiy;
    int size;
    
    DArray();
    
    void resize();
    
    void insert(int newInt);
    
    int readIn(string fileName);
    
    void lookBack();

};

#endif /* DArray_h */






