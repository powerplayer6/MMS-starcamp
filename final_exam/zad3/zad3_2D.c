#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <pthread.h>
#include <math.h>
#include <string.h>
#define THREAD_COUNT 2

typedef struct vektor
{
    int n, m;
    double arr[99][99];
    char* fname;
} vektor;

int n,m;
vektor vic;
pthread_mutex_t mux;

void *routine (void* arg)
{
    sleep(1);
    int index = *(int*)arg;
    index++;
    double sum=0, result=0, tmp=0;
    for(int i=index-1; i<=n; i+=m*index)
    {
        /*if(i>(n+1))
        {
            break;
        }*/
        for(int j=0; j<m; j++)
        {
            tmp=vic.arr[i][j]*vic.arr[i][j];
            sum=sum+tmp;
        }
        result=sqrt(sum);
        printf("%lf", result);
        printf("\n");
    }
}

int main()
{
    char *fname;
    printf("Input rows: ");
    scanf("%d", &n);
    printf("Input cols: ");
    scanf("%d", &m);
    double arr[n][m];
    for(int i=0; i<n; i++)
    {
      for(int j=0;j<m;j++)
      {
        scanf("%lf", &arr[i][j]);
      }
    }
    printf("Input file name: ");
    scanf("%s", fname);
    

    for(int i=0; i<n; i++)
    {
      for(int j=0;j<m;j++)
      {
        vic.arr[i][j]=arr[i][j];
      }
    }

    vic.fname=fname;
    vic.n=n;
    vic.m=m;

    printf("\n");

    pthread_t th[THREAD_COUNT];
    for(int i=0; i<THREAD_COUNT; i++)
    {
        int *num=malloc(sizeof(int));
        *num=i;
        if(pthread_create(th+i, NULL, routine, num))
        {
            perror("create");
            return EXIT_FAILURE;
        }
    }
    for(int i=0; i<THREAD_COUNT; i++)
    {
        if(pthread_join(th[i], NULL))
        {
            perror("join");
            return EXIT_FAILURE;
        }
    }

    return 0;
}