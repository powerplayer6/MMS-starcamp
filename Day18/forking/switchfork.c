#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    pid_t pid=fork();
    switch (pid){
        case -1:
            perror("Fork");
            exit(EXIT_FAILURE);
        case 0:
            for(int i=0; i<10; i++)
            {
                printf("Hello I am child\n");
                sleep(1);
            }
            break;
        default:
            for(int i=0; i<10; i++)
            {
                printf("Hello I am parent\n");
                sleep(1);
            }
            wait(NULL);
            break;
    }
    return EXIT_SUCCESS;
}