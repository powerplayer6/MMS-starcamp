#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n*sizeof(int));
    if(NULL==arr)
    {
        perror("No memory!");
        exit(-1);
    }
    for (int i=0; i<n; i++)
    {
        arr[i]= rand() % 10;
    }
    for (int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}