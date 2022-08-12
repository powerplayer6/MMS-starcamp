#pragma once
#include <stdio.h>
#include <stdint.h>

void setBit(uint64_t *mask, unsigned bit)
{
    *mask |= (1ULL<<bit);
}

void clearBit(uint64_t *mask, unsigned bit)
{
    *mask &= ~(1<<bit);
}

int checkBit(uint64_t mask, unsigned bit)
{
    return !!(mask&(1<<bit));
}

void flipBit(uint64_t *mask, unsigned bit)
{
    *mask ^= 1ULL << bit;
}