#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#define COUNT 10

unsigned long long count = 0;
pthread_mutex_t mux;

void *routine (void* arg)
{
    for (int i=0; i<10000; i++)
    {
        pthread_mutex_lock(&mux);
        count++;
        pthread_mutex_unlock(&mux);
    }
}

int main()
{
    srand(time(NULL));
    pthread_t th[COUNT];
    for(int i=0; i<COUNT; i++)
    {
        if(pthread_create(&th[i], NULL, routine, NULL))
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
    printf("%llu\n", count);
    return EXIT_SUCCESS;
}