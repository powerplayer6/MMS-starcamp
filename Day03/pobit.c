#include <stdio.h>
int main()
{
    __uint16_t mask = 0xff;
    int bit = 0;
    printf("%d\n",!!(mask & (1 << bit)));
    return 0;
}