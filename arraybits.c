#include <stdio.h>
#include <stdint.h>
#define N 10

void setBit(uint32_t* maska, unsigned len, unsigned bit)
{
    
}

void printBit(uint32_t *maska, unsigned len)
{
    for(int i=0; i<len; i++)
    {
        for(int j=sizeof(maska[i])*__CHAR_BIT__; j>=0; j--)
        {
            printf("%d ", !!(maska[i]&(1<<j)));
        }
        putchar('\n');
    }
}

int main()
{
    uint32_t mask[N]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printBit(mask, N);
}