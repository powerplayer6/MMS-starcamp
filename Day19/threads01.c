#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void sleep_ms(unsigned ms)
{
    usleep(ms*1000);
}

void *routine(void* arg)
{
    printf("Hello\n");
    sleep_ms(1000);
}

void *routine2(void* arg)
{
    printf("Goodbye\n");
    sleep_ms(500);
}

int main()
{
    pthread_t th1, th2;

    pthread_create(&th1, NULL, routine, NULL);
    pthread_create(&th2, NULL, routine2, NULL);

    pthread_join(th1, NULL);
    pthread_join(th2, NULL);

    //sleep(1);

    printf("Fuck you \n");
    return EXIT_SUCCESS;
}