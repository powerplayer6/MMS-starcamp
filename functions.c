#include <stdio.h>
#include <stdint.h>

void sayHello(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Hello World\n");
    }
}

void setZero(int *a)
{
    *a = 0;
}

void swapNums(int *a, int *b)
{
    int temp = *a;
    *a=*b;
    *b=temp;
}

void setBit(uint64_t *mask, unsigned bit)
{
    *mask |= (1ULL<<bit);
}

void clearBit(uint64_t *mask, unsigned bit)
{
    *mask &= ~(1<<bit);
}

int checkBit(uint64_t mask, unsigned bit)
{
    return !!(mask&(1<<bit));
}

int main()
{
    //sayHello(5);
    //int num = 20;

    int a=10, b=15;

    /*int *ptr;
    ptr = &num;
    printf("%p\n", ptr);*/

    //setZero(&num);
    //printf("%d\n",num);

    printf("%d %d\n",a,b);
    swapNums(&a, &b);
    printf("%d %d\n",a,b);

    return 0;
}