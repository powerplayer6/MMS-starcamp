#include <stdio.h>
#include <stdint.h>

int setBit(uint32_t *mask, size_t n, size_t bit)
{
    if (n*sizeof(*mask)*__CHAR_BIT__<= bit)
    {
        return 1;
    }
    int index = bit/(sizeof(*mask)*__CHAR_BIT__);
    int b=bit%(sizeof(*mask)*__CHAR_BIT__);
    mask[index] |= (1ULL << b);
    return 0;
}

int clearBit(uint32_t *mask, size_t n, size_t bit)
{
    if (n*sizeof(*mask)*__CHAR_BIT__<= bit)
    {
        return 1;
    }
    int index = bit/(sizeof(*mask)*__CHAR_BIT__);
    int b=bit%(sizeof(*mask)*__CHAR_BIT__);
    mask[index] &= ~(1ULL << b);
    return 0;
}

int flipBit(uint32_t *mask, size_t n, size_t bit)
{
    if (n*sizeof(*mask)*__CHAR_BIT__<= bit)
    {
        return 1;
    }
    int index = bit/(sizeof(*mask)*__CHAR_BIT__);
    int b=bit%(sizeof(*mask)*__CHAR_BIT__);
    mask[index] ^= (1ULL << b);
    return 0;
}

int checkBit(uint32_t *mask, size_t n, size_t bit)
{
    if (n*sizeof(*mask)*__CHAR_BIT__<= bit)
    {
        return -1;
    }
    int index = bit/(sizeof(*mask)*__CHAR_BIT__);
    int b=bit%(sizeof(*mask)*__CHAR_BIT__);
    return !!(mask[index]&(1ULL<<b));
}

void printBit(uint32_t *mask, size_t n)
{
    for (int i = n*sizeof(*mask)*__CHAR_BIT__-1; i >= 0; i--)
    {
        printf("%d", checkBit(mask, n, i));
    }
    putchar('\n');
    
}

//#define LEN 5;

int main ()
{
    unsigned len = 5;
    uint32_t mask[]={1, 20, 30, 40, 50};
    printf("%d\n", checkBit(mask, len, 0));
    setBit(mask, len, 1);
    clearBit(mask, len, 0);
    flipBit(mask, len, 2);
    printBit(mask, len);
    return 0;
}