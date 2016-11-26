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
}


Page::Page(int newNum)
{
    number = newNum;
}


Page& Page::operator =(const Page &copyThis)
{
    number = copyThis.number;
    place = copyThis.place;
    return *this;
}
