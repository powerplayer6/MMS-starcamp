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
        srand(time(NULL));
        int num=1+rand()%100;
        write(fd[1], &num, sizeof(num));
        close(fd[1]);
    }
    else{
        close(fd[1]);
        int numFromChild;
        read(fd[0], &numFromChild, sizeof(numFromChild));
        close(fd[0]);
        wait(NULL);
        printf("num from child: %d\n", numFromChild);
    }

    return EXIT_SUCCESS;
}