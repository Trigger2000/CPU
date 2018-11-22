//
//  Header.h
//  CPU
//
//  Created by Илья  on 14/11/2018.
//  Copyright © 2018 Илья . All rights reserved.
//

#ifndef PROC_h
#define PROC_h

#include "Stack.h"
#include "PREPROC.h"

void processor (int* bcd, FILE* logs, struct labels* lbl);
void comanalyzer (int* com, FILE* logs, int* bcd, int* counter, Stack* foruse, int* checker, double* registers, struct labels* lbl, int* returnpoint);

void processor (int* bcd, FILE* logs, struct labels* lbl)
{
    Stack foruse;
    StackInit(&foruse);
    double registers[5] = {0,0,0,0,0};
    
    int com = 0, counter = 0, checker = 0, returnpoint = 0;
    for (counter = 0; checker != 1; counter++)
    {
        com = bcd[counter];
        comanalyzer(&com, logs, bcd, &counter, &foruse, &checker, registers, lbl, &returnpoint);
    }
    
    free(foruse.data);
}

void comanalyzer (int* com, FILE* logs, int* bcd, int* counter, Stack* foruse, int* checker, double* registers, struct labels* lbl, int* returnpoint)
{
    switch (*com)
    {
        #define CMD_DEF(name, num, code) case num: code;

        #include "Command1.h"
        #include "Command2.h"
        #include "Command3.h"
            
        #undef CMD_DEF
        default:
            break;
    }
}

#endif
