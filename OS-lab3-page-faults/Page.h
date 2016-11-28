//
//  Page.h
//  OS-lab3-page-faults
//
//  Created by Tyler Blanton on 11/25/16.
//  Copyright © 2016 Tyler Blanton. All rights reserved.
//

#ifndef Page_h
#define Page_h

#include <stdio.h>

class Page
{
public:
    int number, place, frequency, distanceFromSpot;
    
    Page();
    
    Page(int newNum);
    
    Page& operator =(const Page &copyThis);
};

#endif /* Page_h */
