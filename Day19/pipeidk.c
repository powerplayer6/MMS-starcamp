#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>

int main()
{
    int fd[2];
    if (pipe(fd)==-1)
    {
        perror("Pipe");
        return EXIT_FAILURE;
    }

    pid_t pid=fork();

    if (-1==pid)
    {
        perror("fork");
        return EXIT_FAILURE;
    }

    if(0==pid)
    {
        close(fd[0]);
        //srand(time(NULL));
        //int num=1+rand()%100;
        char *str="Hello MMS!";
        unsigned len=strlen(str)+1;
        write(fd[1], &len, sizeof(len));
        write(fd[1], str, sizeof(str)+1);
        close(fd[1]);
    }
    else{
        close(fd[1]);
        //int numFromChild;
        char buff[200];
        unsigned len;
        read(fd[0], &len, sizeof(len));
        read(fd[0], buff, len);
        close(fd[0]);
        wait(NULL);
        printf("String from child: %s\n", buff);
    }

    return EXIT_SUCCESS;
}