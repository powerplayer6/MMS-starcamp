//#ifndef __RANDS__
//#define __RANDS__
#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
//#endif

int randint(int min, int max)
{
    return min+rand()%(max-min+1);
}

double randreal(double min, double max)
{
    return min+((double)rand()/RAND_MAX*(max-min));
}

void randinit()
{
    srand(time(NULL));
}