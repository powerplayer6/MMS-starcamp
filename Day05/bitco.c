#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <float.h>

size_t bitsNCount(size_t count, size_t bits, ...)
{
    int test=0;
    int broj=0;
    int mask;
    va_list args;
    va_start(args, bits);
    for(int i=0; i<count; i++)
    {
        mask=va_arg(args, int);
        for (int j = 0; j < sizeof(int)*__CHAR_BIT__; j++)
        {
            if(!!(mask&(1<<j))==1)
            {
                test++;
            }
        }  
        if(test==bits)
        {
            broj++;
        } 
    }
    return broj;
}

int main()
{
    printf("%lu\n", bitsNCount(5,2,1,2,3,4,5));
    return 0;
}