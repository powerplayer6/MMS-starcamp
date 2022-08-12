#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>
#include <signal.h>

void getHint(int sig)
{
    printf("[Hint]: Fuck you!\n");
}

int main()
{
    pid_t pid=fork();

    if (-1==pid)
    {
        perror("fork");
        return EXIT_FAILURE;
    }

    if(0==pid)
    {
       sleep(5);
       kill(getppid(), SIGUSR1);
    }
    else{
        struct sigaction sa;
        sa.sa_handler=getHint;
        sa.sa_flags=SA_RESTART;
        sigaction(SIGUSR1, &sa, NULL);
        int num;
        printf("69+1=?\n");
        scanf("%d", &num);
        if(70==num)
        {
            printf("Nice\n");
        } else {printf("Not nice\n");}
        kill(pid, SIGTERM);
        wait(NULL);
    }

    return EXIT_SUCCESS;
}