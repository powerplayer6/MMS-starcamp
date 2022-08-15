#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <pthread.h>

int yesset(const char* s){
    int count = 0;
    while(*s != '\0'){
        for(int i=7; i>=0; --i){
            if((*s & (1 << i)) == 1) count++;
        }
        s++;
    }
    return count;
}

void *routine (void* arg)
{
    sleep(1);
    char* nm;
    char buff[99999];
    nm=(char*)arg;
    int sum=0;
    printf("%s\n", nm);
    FILE *fp = fopen(nm, "rb");
    if(fp==NULL)
        {
            printf("%s - error!\n", nm);
        }
        else
        {
            while(fgets(buff, 99, fp)!=NULL){}
            sum=yesset(buff);
            printf("%s - %d\n", nm, sum);
        }
}

int main(int argc, char* argv[])
{
    pthread_t th[argc-1];
    for(int i=1; i<argc; i++)
    {
        if(pthread_create(th+(i-1), NULL, routine, argv[i]))
        {
            perror("create");
            return EXIT_FAILURE;
        }
    }
    for(int i=1; i<argc; i++)
    {
        if(pthread_join(th[i-1], NULL))
        {
            perror("join");
            return EXIT_FAILURE;
        }
    }
    return 0;
}