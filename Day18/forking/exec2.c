#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

int main()
{
    printf("Hello\n");
    pid_t pid1 = fork();
    if (0==pid1)
    {
        execlp("ls", "ls", "-l", "-a", "fork.c", NULL);
    }
    else {
        pid_t pid2=fork();
        if(0==pid2)
        {
            char *arguments[] = {"ping", "www.google.com", "-c", "3", NULL};
            execvp("ping", arguments);
        }
        else{
            wait(NULL);
            wait(NULL);
            printf("Bye bye!\n");
        }
    }
    return 0;
}