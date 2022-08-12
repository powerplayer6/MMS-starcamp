#include <stdio.h>
#include <stdint.h>
#include "bitmasks.h"

int main()
{
    uint64_t mask = 0b0000;
    setBit(&mask, 1);
    printf("%d\n", checkBit(mask, 1));
}