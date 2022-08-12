#include <stdio.h>
#define LEN 5

void map(int* arr, int len, int (*f)(int))
{
    for(int i=0;i<len;i++)
    {
        arr[i]=f(arr[i]);
    }
}

int increment(int a)
{
    a++;
    return a; 
}

void prarr(int* arr, int len)
{
   for(int i=0;i<len;i++)
    {
        printf("%d\n", arr[i]);
    } 
}

int mult(int a, int b)
{
    return a*b;
}

int div(int a, int b)
{
    return a/b;
}

int sum(int a, int b)
{
    return a+b;
}

int sub(int a, int b)
{
    return a-b;
}


typedef unsigned int liters_t;


typedef int (*operation_t)(int, int);
operation_t getOp(char op)
{
    switch(op)
    {
        case '+':
            return sum;
        case '-':
            return sub;
        case '/':
            return div;
        case '*':
            return mult;
        default:
            return NULL;
    }

}
int main()
{
    int mass[LEN]={1, 2, 3, 4, 5};
    map(mass, LEN, increment);
    prarr(mass, LEN);
    printf("%d\n", getOp('+')(5,6));
    liters_t rakiaBottle;
}