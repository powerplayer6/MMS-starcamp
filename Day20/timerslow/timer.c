#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <wait.h>

typedef struct timeval timeval;

int main(int argc, char* argv[])
{
    timeval tv1, tv2;
    gettimeofday(&tv1, NULL);
    //printf("%lu %lu\n", tv1.tv_sec, tv1.tv_usec);
    
    int pid=fork();

    if(pid<0)
    {
        perror("dies of cringe\n");
        exit(-1);
    } else if(pid==0)
    {   //child 
        execvp(argv[1], argv+1);
        perror("dies of cringe\n");
        exit(-1);
    } else if(pid>0)
    {   //parent
        int status;
        wait(&status);
        if(WIFEXITED(status)&&WEXITSTATUS(status)==0)
        {
            printf("Child has died successfully!\n");
        }
        else {
            printf("Child has NOT died successfully!\n");
        }
        gettimeofday(&tv2, NULL);
        printf("Elapsed time: %lfs\n", 
                            ((tv2.tv_sec - tv1.tv_sec)*1000000 + 
                            (tv2.tv_usec - tv1.tv_usec))/1000000.0);
        exit(0);
    }

    perror("dies of cringe\n");

    return 0;
}