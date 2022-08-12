#include <stdio.h>
#include "rands.h"
#include <math.h>

int compD(const void* num1, const void* num2)
{
    double a =*(double*)num1;
    double b =*(double*)num2;
    if(fabs(a-b)<0.0001)
    {
        return 0;
    } else if (a>b){return 1;}
    else return -1;
}

void prarr(double* arr, int cnt)
{
    for(int i=0;i<cnt;i++)
    {
        printf("%lf\n",arr[i]);
    }
}

int main()
{
    randinit();
    double arr[count];
    for(int i=0;i<count;i++)
    {
        arr[i]=randreal(5.0,10.0);
    }
    qsort(arr, count, sizeof(*arr), compD);
    prarr(arr, count);
}
