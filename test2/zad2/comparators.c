#pragma once
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int compD(const void* num1, const void* num2)
{
    int a = *(int*)num1;
    int b = *(int*)num2;
    if (a>b){return 1;}
    else return -1;
}

int compA(const void* num1, const void* num2)
{
    int a = *(int*)num1;
    int b = *(int*)num2;
    if (a<b){return 1;}
    else return -1;
}

int compS(const void* num1, const void* num2)
{
    
    int a = *(int*)num1;
    int b = *(int*)num2;
    int c = a/10+a%10;
    int d = b/10+b%10;
    if (c>d){return 1;}
    else return -1;
}

int compABS(const void* num1, const void* num2)
{
    int a = fabs(*(int*)num1);
    int b = fabs(*(int*)num2);
    if (a>b){return 1;}
    else return -1;
}

void printArr(int* arr, int cnt)
{
    for(int i=0; i<cnt;i++)
    {
        printf("%d\n", arr[i]);
    }
}