#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    for(int i=1; i<argc; i++)
    {
        pid_t pid = fork();
        if(0==pid){
            char *args[]={argv[i], NULL};
            execvp(argv[i], args);
            sleep(1);
            exit(EXIT_SUCCESS);
        } else{
            wait(NULL);
        }
    }
    /*for(int i=1; i<argc; i++)
    {
        wait(NULL);
    }*/
    return EXIT_SUCCESS;
}