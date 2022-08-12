#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <float.h>

unsigned zerosCount(uint64_t mask1, uint32_t mask2, uint16_t mask3, uint8_t mask4)
{
    int sum=0;
    for(int i = sizeof(mask1)*__CHAR_BIT__-1; i >= 0; i--)
    {
        if(!!!(mask1&(1<<i)))
        {
            sum++;
        }
    }
    for(int i = sizeof(mask2)*__CHAR_BIT__-1; i >= 0; i--)
    {
        if(!!!(mask2&(1<<i)))
        {
            sum++;
        }
    }
    for(int i = sizeof(mask3)*__CHAR_BIT__-1; i >= 0; i--)
    {
        if(!!!(mask3&(1<<i)))
        {
            sum++;
        }
    }
    for(int i = sizeof(mask4)*__CHAR_BIT__-1; i >= 0; i--)
    {
        if(!!!(mask4&(1<<i)))
        {
            sum++;
        }
    }
    printf("%d\n", sum);
    return 0;
}

void flipOddBits(uint64_t* mask)
{
    for(int i=sizeof(*mask)*__CHAR_BIT__; i>=0; i--)
    {
        if(i%2!=0)
        {*mask ^= 1ULL << i;}
    }
    //return mask;
}

void printMask(uint64_t mask)
{
    for(int i=sizeof(mask)*__CHAR_BIT__; i>=0; i--)
    {
        
        printf("%d", !!(mask&(1ULL<<i)));
    }
    printf("\n");
}

void mirrorBits(uint16_t* mask)
{
    for(int i=sizeof(*mask)*__CHAR_BIT__; i>=0; i--)
    {
        *mask ^= 1ULL << i;
    }
}

int main()
{
    uint64_t maska = 1;
    uint16_t maska2 = 1;
    zerosCount(0b0000, 0b0000, 0b0000, 0b0000);
    printMask(maska);
    flipOddBits(&maska);
    printMask(maska);
    mirrorBits(&maska2);
    printMask(maska2);
    return 0;
}