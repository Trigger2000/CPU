//
//  main.cpp
//  CPU
//
//  Created by Илья  on 06/11/2018.
//  Copyright © 2018 Илья . All rights reserved.
//

#include "ASM.h"
#include "PROC.h"
#include "PREPROC.h"

long exploreparam (FILE* in);

int main()
{
    FILE* logs = fopen ("/Users/ilya1/Desktop/code/CPU/CPU/log.txt", "w");
    FILE* in = fopen("/Users/ilya1/Desktop/code/CPU/CPU/in.txt", "r");
    assert(logs != NULL);
    assert(in != NULL);
    
    int* bcd = NULL;
    long bcdsize = exploreparam(in);
    bcd = (int*)calloc(bcdsize, sizeof(int));

    asmb(in, logs, bcd);
    assert(bcd != NULL);
    
    long labelcounter = countlabels(bcd, bcdsize);
    struct labels* lbl = (struct labels*)calloc(labelcounter, sizeof(struct labels));
    preprocessor(bcd, logs, bcdsize, lbl);
    
    processor(bcd, logs, lbl);
    
    fclose(logs);
    return 0;
}

long exploreparam (FILE* in)
{
    fseek(in, 0, SEEK_END);
    long size = ftell(in);
    fseek(in, 0, SEEK_SET);
    
    char* arrayin = (char*)calloc(size + 5, sizeof(char));
    fread(arrayin, sizeof(char), size, in);
    
    long bcdsize = amount(arrayin);
    return bcdsize;
}
