//
//  Page.cpp
//  OS-lab3-page-faults
//
//  Created by Tyler Blanton on 11/25/16.
//  Copyright © 2016 Tyler Blanton. All rights reserved.
//

#include <chrono>
#include <sys/time.h>
#include <unistd.h>
#include "Page.h"

Page::Page()
{
    number = -1;
    place = 0;
    frequency = 0;
    distanceFromSpot = 0;
}


Page::Page(int newNum)
{
    number = newNum;
    place = 0;
    frequency = 0;
    distanceFromSpot = 0;
}


Page& Page::operator =(const Page &copyThis)
{
    number = copyThis.number;
    place = copyThis.place;
    frequency = copyThis.frequency;
    return *this;
}
