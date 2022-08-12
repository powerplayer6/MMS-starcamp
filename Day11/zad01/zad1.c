#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
//#define COUNT 10
//#define MIN 15
//#define MAX 50

int compD(const void* num1, const void* num2)
{
    int a = *(int*)num1;
    int b = *(int*)num2;
    if (a>b){return 1;}
    else return -1;
}

int compA(const void* num1, const void* num2)
{
    int a = *(int*)num1;
    int b = *(int*)num2;
    if (a<b){return 1;}
    else return -1;
}

int compS(const void* num1, const void* num2)
{
    
    int a = *(int*)num1;
    int b = *(int*)num2;
    int c = a/10+a%10;
    int d = b/10+b%10;
    if (c>d){return 1;}
    else return -1;
}

int compABS(const void* num1, const void* num2)
{
    int a = fabs(*(int*)num1);
    int b = fabs(*(int*)num2);
    if (a>b){return 1;}
    else return -1;
}

void printArr(int* arr, int cnt)
{
    for(int i=0; i<cnt;i++)
    {
        printf("%d\n", arr[i]);
    }
}

int main()
{
    srand(time(0));
    int (*f[4])(const void* num1, const void* num2);
    f[0]=compD;
    f[1]=compA;
    f[2]=compS;
    f[3]=compABS;
    int op, flag=0;
    int arr[COUNT];
    for (int i = 0; i < COUNT; i++) {
        arr[i] = (rand() %
        (MAX - MIN + 1)) + MIN;
    }
    while(1){
        printf("1. Ascending\n2. Descending\n3. Sum of digits\n4. Absolute value\n");
        flag = 0;
        scanf("%d", &op);
        switch(op)
        {
            case 1:
                qsort(arr, COUNT, sizeof(*arr), f[0]);
                flag = 1;
                break;
            case 2:
                qsort(arr, COUNT, sizeof(*arr), f[1]);
                flag =1;
                break;
            case 3:
                qsort(arr, COUNT, sizeof(*arr), f[2]);
                flag = 1;
                break;
            case 4:
                qsort(arr, COUNT, sizeof(*arr), f[3]);
                flag = 1;
                break;
            default:
                printf("Error!\n");
                flag = 0;
                break;
        }
        if(flag==1)
        {
            printArr(arr, COUNT);
        }
    }
    return 0;
}