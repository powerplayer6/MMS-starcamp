#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double randDBL(double min, double max)
{
    double range = (max-min);
    double div=RAND_MAX/range;
    return min+(rand()/div);
}

int main()
{
    srand(time(NULL));
    int n, m, p;

    printf("How many between 0 and 1: ");
    scanf("%d", &n);

    float* arr = (float*)malloc(n*sizeof(float));
    if(NULL==arr)
    {
        perror("No memory!");
        exit(-1);
    }
    for (int i=0; i<n; i++)
    {
        arr[i]= randDBL(0, 1.0);
    }

    printf("\nHow many between 1 and 2: ");
    scanf("%d", &m);
    arr = realloc(arr, (n+m)*sizeof(float));
    for (int i=n; i<n+m; i++)
    {
        arr[i]= randDBL(1.0, 2.0);
    }

    printf("\nHow many between 2 and 3: ");
    scanf("%d", &p);
    arr = realloc(arr, (n+m+p)*sizeof(float));
    for (int i=n+m; i<n+m+p; i++)
    {
        arr[i]= randDBL(2.0, 3.0);
    }

    printf("\n");
    for (int i=0; i<n+m+p; i++)
    {
        printf("%f ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}