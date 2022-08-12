#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "rands.h"

int main()
{
    randinit();
    printf("%d\n", RAND_MAX);
    for(int i=0;i<10; i++)
    {
        printf("%d\n", rand());
    }
    printf("%d\n", randint(1,6));
    printf("%lf\n", randreal(1,2));
    return 0;
}