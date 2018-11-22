//
//  Header.h
//  CPU
//
//  Created by Илья  on 12/11/2018.
//  Copyright © 2018 Илья . All rights reserved.
//

#ifndef ASM_h
#define ASM_h

#include "Stack.h"

void asmb (FILE* in, FILE* logs, int* bcd);
long exploreparam (FILE* in);
long amount (char* arrayin);
void recogniser (char* arrayin, int* bcd, long size);
void analyzer (long* counter, long* bcdcounter, char* temp, int* bcd, char* arrayin, long size);
void createcommand (int* bcd, long* bcdcounter, int comnumber);
int transform (char* num, int amnum);
int findword (char* searcharray, long* startnum, char* word, long size);

void asmb (FILE* in, FILE* logs, int* bcd) //bcd = Byte CoDe
{
    fseek(in, 0, SEEK_END);
    long size = ftell(in);
    fseek(in, 0, SEEK_SET);
    
    char* arrayin = (char*)calloc(size + 3, sizeof(char));
    fread(arrayin, sizeof(char), size, in);
    
    long bcdsize = amount(arrayin);
    
    recogniser(arrayin, bcd, size);
    
    fprintf(logs, "---------------\nByte code\n---------------\n");
    int counter = 0;
    for (counter = 0; counter < bcdsize; counter++)
    {
        fprintf(logs, "%d", bcd[counter]);
        if (counter % 50 == 0 && counter != 0) fprintf(logs, "\n");
    }
    fprintf(logs, "\n---------------\n");
}

long amount (char* arrayin)
{
    long counter = 0, operandnum = 0, funcnum = 0;
    for (counter = 0; arrayin[counter] != '\0'; counter++)
    {
        if ((arrayin[counter] == ' ') && (arrayin[counter + 1] != 'r')) operandnum++ ;
        if (arrayin[counter] == '\n') funcnum++ ;
    }
    
    return 2 * funcnum + operandnum + 2;
}

void recogniser (char* arrayin, int* bcd, long size)
{
    long counter = 0, bcdcounter = 0;
    for (counter = 0; counter < size; counter++)
    {
        char temp[10] = ".";
        findword(arrayin, &counter, temp, size);
        analyzer(&counter, &bcdcounter, temp, bcd, arrayin, size);
    }
}

void analyzer (long* counter, long* bcdcounter, char* temp, int* bcd, char* arrayin, long size)
{
    if (strcmp(temp, "push") == 0) // cmd 1
    {
        createcommand(bcd, bcdcounter, 1);
        *counter += 1;
        
        char temp[10] = ".";
        int len = findword(arrayin, counter, temp, size);
        int num = 0;
        
        if (strcmp(temp, "rax") == 0) //cmd 101
        {
            bcd[*bcdcounter - 1] = 101;
        }
        else if (strcmp(temp, "rbx") == 0) //cmd 102
        {
            bcd[*bcdcounter - 1] = 102;
        }
        else if (strcmp(temp, "rcx") == 0) //cmd 103
        {
            bcd[*bcdcounter - 1] = 103;
        }
        else if (strcmp(temp, "rdx") == 0) //cmd 104
        {
            bcd[*bcdcounter - 1] = 104;
        }
        else
        {
            num = transform(temp, len);
            bcd[*bcdcounter] = num;
            *bcdcounter += 1;
        }
    }
    
    if (strcmp(temp, "pop") == 0)
    {
        char temp[10] = ".";
        *counter += 1;
        findword(arrayin, counter, temp, size);
        
        if (strcmp(temp, "rax") == 0) //cmd 201
        {
            createcommand(bcd, bcdcounter, 201);
        }
        if (strcmp(temp, "rbx") == 0) //cmd 202
        {
            createcommand(bcd, bcdcounter, 202);
        }
        if (strcmp(temp, "rcx") == 0) //cmd 203
        {
            createcommand(bcd, bcdcounter, 203);
        }
        if (strcmp(temp, "rdx") == 0) //cmd 204
        {
            createcommand(bcd, bcdcounter, 204);
        }
    }
    
/*     #define CMD_DEF(name, num, code) \
     if (strcmp(temp, "push") == 0) \
     { \
     createcommand(bcd, bcdcounter, 1); \
     *counter += 1; \
     \
     char temp[10] = "."; \
     int len = findword(arrayin, counter, temp, size); \
     int num = 0; \
     num = transform(temp, len); \
     bcd[*bcdcounter] = num; \
     *bcdcounter += 1; \
     } \
     else if ((strcmp(temp, #name) == 0) && (temp[1] == 'u')) \
     { \
     bcd[*bcdcounter - 1] = num; \
     } \
     else if ((strcmp(temp, #name) == 0) && (temp[1] == 'o')) \
     { \
     createcommand(bcd, bcdcounter, num); \
     }
     
     #include "Command2.h"
     
     #undef CMD_DEF */
    
#define CMD_DEF(name, num, code) \
if (strcmp(temp, #name) == 0) \
{ \
createcommand(bcd, bcdcounter, num); \
}
    
#include "Command1.h"
    
#undef CMD_DEF
  
    
/* #define CMD_DEF(name, num, code) \
if (strcmp(temp, #name) == 0) \
{ \
createcommand(bcd, bcdcounter, num); \
*counter += 1; \
\
char temp[10]; \
int len = findword(arrayin, counter, temp, size); \
int num = 0; \
num = transform(temp, len); \
\
bcd[*bcdcounter] = num; \
*bcdcounter += 1; \
}
    
#include "Command3.h"
    
#undef CMD_DEF */
    
    if (strcmp(temp, ":") == 0)
     {
        createcommand(bcd, bcdcounter, 10);
        *counter += 1;
        
        char temp[10] = ".";
        int len = findword(arrayin, counter, temp, size);
        int num = 0;
        num = transform(temp, len);
        
        bcd[*bcdcounter] = num;
        *bcdcounter += 1;
    }
    
    if (strcmp(temp, "jmp") == 0)
    {
        createcommand(bcd, bcdcounter, 11);
        *counter += 1;
        
        char temp[10] = ".";
        int len = findword(arrayin, counter, temp, size);
        int num = 0;
        num = transform(temp, len);
        
        bcd[*bcdcounter] = num;
        *bcdcounter += 1;
    }
    
    if (strcmp(temp, "ja") == 0)
    {
        createcommand(bcd, bcdcounter, 12);
        *counter += 1;
        
        char temp[10] = ".";
        int len = findword(arrayin, counter, temp, size);
        int num = 0;
        num = transform(temp, len);
        
        bcd[*bcdcounter] = num;
        *bcdcounter += 1;
    }
    
    if (strcmp(temp, "jb") == 0)
    {
        createcommand(bcd, bcdcounter, 13);
        *counter += 1;
        
        char temp[10] = ".";
        int len = findword(arrayin, counter, temp, size);
        int num = 0;
        num = transform(temp, len);
        
        bcd[*bcdcounter] = num;
        *bcdcounter += 1;
    }
    
    if (strcmp(temp, "je") == 0)
    {
        createcommand(bcd, bcdcounter, 14);
        *counter += 1;
        
        char temp[10] = ".";
        int len = findword(arrayin, counter, temp, size);
        int num = 0;
        num = transform(temp, len);
        
        bcd[*bcdcounter] = num;
        *bcdcounter += 1;
    }
    
    if (strcmp(temp, "jae") == 0)
    {
        createcommand(bcd, bcdcounter, 15);
        *counter += 1;
        
        char temp[10] = ".";
        int len = findword(arrayin, counter, temp, size);
        int num = 0;
        num = transform(temp, len);
        
        bcd[*bcdcounter] = num;
        *bcdcounter += 1;
    }
    
    if (strcmp(temp, "jbe") == 0)
    {
        createcommand(bcd, bcdcounter, 16);
        *counter += 1;
        
        char temp[10] = ".";
        int len = findword(arrayin, counter, temp, size);
        int num = 0;
        num = transform(temp, len);
        
        bcd[*bcdcounter] = num;
        *bcdcounter += 1;
    }
    
    if (strcmp(temp, "jne") == 0)
    {
        createcommand(bcd, bcdcounter, 17);
        *counter += 1;
        
        char temp[10] = ".";
        int len = findword(arrayin, counter, temp, size);
        int num = 0;
        num = transform(temp, len);
        
        bcd[*bcdcounter] = num;
        *bcdcounter += 1;
    }
    
    if (strcmp(temp, "call") == 0)
    {
        createcommand(bcd, bcdcounter, 18);
        *counter += 1;
        
        char temp[10] = ".";
        int len = findword(arrayin, counter, temp, size);
        int num = 0;
        num = transform(temp, len);
        
        bcd[*bcdcounter] = num;
        *bcdcounter += 1;
    }
    
}

void createcommand (int* bcd, long* bcdcounter, int comnumber)
{
    bcd[*bcdcounter] = 0;
    *bcdcounter += 1;
    bcd[*bcdcounter] = comnumber;
    *bcdcounter += 1;
}

int transform (char* num, int amnum)
{
    int number = 0, helper = 0, stoppoint = 0;
    
    if (num[0] == '-')
    {
        stoppoint = 1;
    }
    
    while (amnum > stoppoint)
    {
        number = number + ((int)num[amnum - 1] - (int)'0') * pow (10, helper);
        helper++;
        amnum--;
    }
    
    if (stoppoint == 1) number *= (-1);
    
    return number;
}

int findword (char* searcharray, long* startnum, char* word, long size)
{
    int incounter = 0;
    for (; searcharray[*startnum] != ' ' && searcharray[*startnum] != '\n' && *startnum < size; *startnum += 1, incounter++)
    {
        word[incounter] = searcharray[*startnum];
    }
    
    return incounter;
}


#endif
