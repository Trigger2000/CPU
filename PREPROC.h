//
//  Header.h
//  CPU
//
//  Created by Илья  on 14/11/2018.
//  Copyright © 2018 Илья . All rights reserved.
//

#ifndef PREPROC_h
#define PREPROC_h

#include "Stack.h"

struct labels
{
    int labelname;
    long labelposition;
};

void preprocessor (int* bcd, FILE* logs, long bcdsize, struct labels* lbl);
long countlabels (int* bcd, long bcdsize);

void preprocessor (int* bcd, FILE* logs, long bcdsize, struct labels* lbl)
{
    long counter = 0, labelcounter = 0;
    
    for (counter = 0; counter < bcdsize - 2; counter++)
    {
        if ((bcd[counter] == 0) && (bcd[counter + 1] == 10))
        {
            lbl[labelcounter].labelname = bcd[counter + 2];
            lbl[labelcounter].labelposition = counter + 3;
            labelcounter++;
        }
    }
}

long countlabels (int* bcd, long bcdsize)
{
    long counter = 0, labelcounter = 0;
    for (counter = 0; counter < bcdsize - 2; counter++)
    {
        if ((bcd[counter] == 0) && (bcd[counter + 1] == 10))
        {
            labelcounter++;
        }
    }
    
    return labelcounter;
}

#endif
