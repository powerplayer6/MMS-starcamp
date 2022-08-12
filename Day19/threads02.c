#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#define COUNT 10

void *routine (void* arg)
{
    sleep(rand()%10);
    printf("Number: %d\n", rand()%100);
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
    return EXIT_SUCCESS;
}