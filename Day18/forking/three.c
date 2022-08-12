#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

int main()
{
    pid_t pid=fork();
    switch (pid){
        case -1:
            perror("Fork");
            exit(EXIT_FAILURE);
        case 0:
            //child
            //printf("PID: %d PPID: %d\n", getpid(), getppid());
            pid_t pid2=fork();
            if(-1==pid2)
            {
                perror("Fork");
                exit(EXIT_FAILURE);
            }
            if(pid2==0)
            {
                // child child
                printf("PID: %d PPID: %d\n", getpid(), getppid());
            } else
            {
                printf("PID: %d PPID: %d\n", getpid(), getppid());
                wait(NULL);
            }
            break;
        default:
            //parent
            printf("PID: %d PPID: %d\n", getpid(), getppid());
            wait(NULL);
            break;
    }
    return EXIT_SUCCESS;
}