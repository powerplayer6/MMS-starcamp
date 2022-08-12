#include <stdio.h>
#include <rands.h>

int main()
{
    randinit();
    printf("%d\n",randint(1,10));
    return 0;
}