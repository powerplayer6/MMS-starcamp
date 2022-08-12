#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <float.h>

size_t onesCount(size_t count, ...)
{
    int sum=0;
    uint32_t mask;
    va_list args;
    va_start(args, count);
    for (int i=0; i < count; i++)
    {
        mask=va_arg(args, uint32_t);
        for(int j=0; j<sizeof(mask)*__CHAR_BIT__-1; j++)
        {
            if(!!(mask&(1ULL<<j)))
            {
                sum++;
            }
        }
    }
    return sum;

}

int main()
{
    printf("%lu\n", onesCount(4, 0x0a, 0, 1, 2));
    printf("%lu\n", onesCount(3, 0xff, 0x131, 0xaaaa));
    printf("%lu\n", onesCount(2, 0b0001, 9));
    return 0;
}