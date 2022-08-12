#include <stdio.h>
#include "rands.h"
#define COUNT 30

int compareint1(const void* num1, const void* num2)
{
    return *(int*)num1-*(int*)num2;
}

int main()
{
    int (*MyComparator)(const void*, const void*);
    MyComparator=compareint1;
    randinit();
    int numbers[COUNT];
    for(int i=0;i<COUNT;i++)
    {
        numbers[i]=randint(0,100);
    }
    qsort(numbers, COUNT, sizeof(numbers[0]), MyComparator);
    for(int i=0;i<COUNT;i++)
    {
        printf("%d\n",numbers[i]);
    }
}