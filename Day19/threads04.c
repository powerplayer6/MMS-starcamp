#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#define COUNT 5


void *routine (void* arg)
{
    sleep(1);
    int val=*(int*)arg;
    printf("Number: %d\n", val);
    free(arg);
}

int main()
{
    srand(time(NULL));
    pthread_t th[COUNT];
    for(int i=0; i<COUNT; i++)
    {
        int* number=malloc(sizeof(int));
        *number=i;
        if(pthread_create(th+i, NULL, routine, number))
        {
            perror("create");
            return EXIT_FAILURE;
        }
    }
    for(int i=0; i<COUNT; i++)
    {
        if(pthread_join(th[i], NULL))
        {
            perror("juin");
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}