//
//  Header.h
//  CPU
//
//  Created by Илья  on 06/11/2018.
//  Copyright © 2018 Илья . All rights reserved.
//

#ifndef Stack_h
#define Stack_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#define INITSIZE 500
double CANARY = 0.125;
//------------------
typedef struct stack Stack;
struct stack
{
    double *data;
    int size, maxsize;
};

void StackInit (Stack* example);
void StackPush (Stack* example, double symb, FILE* logs);
void StackPop (Stack* example, double* val);
double CheckStack (Stack* example, int steps);

void StackInit (Stack* example)
{
    (*example).data = (double*)calloc(INITSIZE, sizeof(double));
    *((*example).data) = 0;
    (*example).data[0] = CANARY;
    (*example).data[1] = CANARY;
    (*example).size = 2;
    (*example).maxsize = INITSIZE;
}

void StackPush (Stack* example, double vvod, FILE * logs)
{
    if ((*example).size == (*example).maxsize - 1)
    {
        ((*example).maxsize) *= 2;
        (*example).data = (double*)realloc((*example).data, (*example).maxsize);
        ((*example).data)[(*example).size - 1] = vvod;
        ((*example).data)[(*example).size] = CANARY;
    }
    else
    {
        (*example).data[(*example).size - 1] = vvod;
        ((*example).data)[(*example).size] = CANARY;
    }
    ((*example).size)++ ;
}

void StackPop (Stack* example, double* val)
{
    if (((*example).data)[(*example).size - 1] != CANARY)
    {
        *val = ((*example).data)[(*example).size - 1];
    }
    else
    {
        ((*example).size)-- ;
        *val = ((*example).data)[(*example).size - 1];
        ((*example).data)[(*example).size] = 0;
        ((*example).data)[(*example).size - 1] = CANARY;
    }
}

double CheckStack (Stack* example, int steps)
{
    return ((*example).data)[(*example).size - 1 - steps];
}

#endif
