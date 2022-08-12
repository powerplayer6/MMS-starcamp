#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int pid=fork();
    if(0 == pid)
    {
        sleep(5);
        printf("Hello im child! My pid is %d My pid is %d\n", getpid(), getppid());
        sleep(2);
    }
    else
    {
        printf("Hello im parent! My pid is %d My pid is %d\n", getpid(), getppid());
        wait(NULL);
        printf("Bye Bye!\n");
    }
    printf("Hello\n");
    return 0;
}