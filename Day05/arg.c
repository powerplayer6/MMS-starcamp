#include <stdio.h>
#include <stdarg.h>
#include <float.h>

int sum(int cnt, ...)
{
    int sum=0;
    va_list args;
    va_start(args, cnt);
    for (int i=0; i < cnt; i++)
    {
        sum += va_arg(args, int);
    }
    va_end(args);
    return sum;
}

int sumAlt(int num, ...)
{
    int sum=num;
    va_list args;
    va_start(args, num);
    int a=va_arg(args, int);
    sum+=a;
    while(a!=0)
    {
        a = va_arg(args, int);
        sum+=a;
    }
    va_end(args);
    return sum;
}

double max(int cnt, ...)
{
    double maxNum = DBL_MIN;
    va_list args;
    va_start(args, cnt);
    for (int i=0; i<cnt; i++)
    {
        double num=va_arg(args, double);
        if(num>maxNum){maxNum=num;}
    }
    va_end(args);
    return maxNum;
}

int main()
{
    printf("%d\n", sum(5, 1, 2, 3, 4, 5));
    printf("%d\n", sumAlt(1, 2, 3, 4, 5, 0));
    printf("%lf\n", max(5, 1.0, 2.0, 3.0, 4.0, 5.0));
}