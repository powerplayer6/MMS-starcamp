#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[])
{
    srand(time(NULL));
    int n=10;
    char* output="", *error="";
    int flag1=0, flag2=0, flag3=0, c;
    while((c=getopt(argc, argv, "n:o:e:"))!=-1)
    {
        switch(c)
        {
            case 'n':              
                n=atoi(optarg);
                flag1=1;
                break;
            case 'o':               
                output=optarg;
                flag2=1;
                break;
            case 'e':
                error=optarg;
                flag3=1;
                break;
            default:
                break;
        }
    }

    if(flag3==1)
    {
        int fd2=open(error, O_WRONLY | O_CREAT | O_APPEND, 0777);
        dup2(fd2, STDERR_FILENO);
    }

    perror("This is a test error");
    
    if(flag2==0)
    {
        for(int i=0; i<n; i++)
        {
            printf("%d ", rand()%10);
        }
        printf("\n");
        return 0;
    } else if(flag2==1)
    {
        int fd1=open(output, O_WRONLY | O_CREAT | O_APPEND, 0777);
        dup2(fd1, STDOUT_FILENO);
        for(int i=0; i<n; i++)
        {
            printf("%d ", rand()%10);
        }
        printf("\n");
        return 0;
    }
    return 0;
}