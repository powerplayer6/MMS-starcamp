#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>

int main(int argc, char* argv[])
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

    if(0==pid)      //child
    {
        close(fd[0]);

        double buff[200], min, max, sum=0, avg=0;

        for (int i=1; i<argc; i++)
        {
            buff[i-1]=atof(argv[i]);
        }

        min=buff[0];
        max=buff[0];
        double cnt=0;

        for (int i=1; i<argc; i++)
        {
            if(buff[i-1]<min)
            {
                min=buff[i-1];
            }
            if(buff[i-1]>max)
            {
                max=buff[i-1];
            }
            sum=sum+buff[i-1];
            cnt=cnt+1;
        }

        avg=sum/cnt;

        write(fd[1], &min, sizeof(min));
        write(fd[1], &max, sizeof(max));
        write(fd[1], &sum, sizeof(sum));
        write(fd[1], &avg, sizeof(avg));

        close(fd[1]);
    }
    else{           //parent
        close(fd[1]);

        double min, max, sum, avg;

        read(fd[0], &min, sizeof(min));
        read(fd[0], &max, sizeof(max));
        read(fd[0], &sum, sizeof(sum));
        read(fd[0], &avg, sizeof(avg));

        close(fd[0]);
        wait(NULL);
        
        printf("Min: %lf\nMax: %lf\nSum: %lf\nAvg: %lf\n", min, max, sum, avg);
    }

    return EXIT_SUCCESS;
}