#include <stdio.h>

void printValue(void *value, int type)
{
    if(1==type){
        printf("Value: %d\n", *(int*)value);
    } else if(2==type){
        printf("Value: %.2lf\n", *(double*)value);
    } else if(3==type){
        printf("Value: %c\n", *(char*)value);
    }
}

int main()
{
    int num=10;
    printValue(&num, 1);
    double pi=3.14;
    printValue(&pi, 2);
    char sym = 'M';
    printValue(&sym, 3);
    return 0;
}