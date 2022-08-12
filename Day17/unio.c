#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main()
{
    char sym = 'Z';
    write(STDOUT_FILENO, &sym, 1);
    sym = '\n';
    write(STDOUT_FILENO, &sym, 1);
    char *msg="MMS C Camp!";
    write(STDOUT_FILENO, msg, strlen(msg));
    write(STDOUT_FILENO, &sym, 1);
    return 0;
}