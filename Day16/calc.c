#include <stdio.h>
#include <string.h>

float suma(int cnt, char* arr[], int flag)
{
    float tmp=0, sum=0;
    for(int i=0+flag; i<cnt; i++)
    {
        sscanf(arr[i], "%f", &tmp);
        sum=sum+tmp;
    }
    return sum;
}

float maxa(int cnt, char* arr[], int flag)
{
    float tmp, max;
    sscanf(arr[flag], "%f", &tmp);
    max=tmp;
    for(int i=0+flag; i<cnt; i++)
    {
        sscanf(arr[i], "%f", &tmp);
        if(max<tmp)
        {
            max=tmp;
        }
    }
    return max;
}

float mina(int cnt, char* arr[], int flag)
{
    float tmp, min;
    sscanf(arr[flag], "%f", &tmp);
    min=tmp;
    for(int i=0+flag; i<cnt; i++)
    {
        sscanf(arr[i], "%f", &tmp);
        if(min>tmp)
        {
            min=tmp;
        }
    }
    return min;
}

int main(int argc, char* argv[])
{
    if(strcmp(argv[1], "-s")==0)
    {
        printf("sum = %.2f\n", suma(argc, argv, 2));
    } else if(strcmp(argv[1], "-m")==0)
    {
        printf("min = %.2f\n", mina(argc, argv, 2));
    } else if(strcmp(argv[1], "-M")==0)
    {
        printf("max = %.2f\n", maxa(argc, argv, 2));
    } else
    {
        printf("sum = %.2f\n", suma(argc, argv, 1));
        printf("min = %.2f\n", mina(argc, argv, 1));
        printf("max = %.2f\n", maxa(argc, argv, 1));
    }
    return 0;
}