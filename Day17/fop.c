#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fr = open("heap.c", O_RDONLY);
    int fw = open("heapcpy.c", O_WRONLY | O_CREAT | O_APPEND, 0777);
    char buff[BUFSIZ];
    int n;
    while ((n=read(fr, buff, BUFSIZ)))
    {
        write(fw, buff, n);
    }
    close(fr);
    close(fw);
    return 0;
}