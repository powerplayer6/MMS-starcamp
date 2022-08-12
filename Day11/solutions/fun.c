#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int c = 0;

void fun()
{
    c++;
}

void f3(int d)
{
    printf("F3\n");
    printf("%d\n",d);
    printf("F3\n");
}

void f2(int c)
{
    printf("F2\n");
    f3(c+100);
    printf("F2\n");
}

void f1(int a, int b)
{
    printf("F1\n");
    f2(a+b);
    printf("F1\n");
}

int flag=0;
void cunts()
{
    static int cnt = 0;
    if(cnt<=50000 && flag==0){
    cnt++;
    printf("%d\n", cnt);}
    else{flag=1; cnt--;printf("%d\n", cnt);}
    cunts();
}



int main()
{   
    /*f1(10, 20);
    fun();
    fun();
    fun();
    printf("%d\n", c);
    cunts();*/

    /*void *p = malloc(sizeof(short));
    printf("%d\n", p);
    printf("%lu\n", sizeof(short));
    short *short_pointer = (short*)p;
    *short_pointer = 100;
    printf("%d\n", *short_pointer);
    free(p);*/

    srand(time(0));
    int *arr = malloc(sizeof(int)*1000);
    realloc(arr, 500*sizeof(int));
    for (int i = 0; i < 500; i++) {
        arr[i] = (rand() %
        (750 - 250 + 1)) + 250;
    }
    int co=0;
    for(int j=0; j<500;j++)
    {
        if(arr[j]==500)
        {
            co++;
        }
    }
    printf("500's: %d\n", co);
    free(arr);
    return 0;
}