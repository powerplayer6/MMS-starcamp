#include <stdio.h>

int main(int argc, char *argp[])
{

    printf("ASDFG %d\n", 100);
    fprintf(stdout, "ASDFG %d\n", 100);
    int a, b;
    scanf("%d",&a);
    fscanf(stdin, "%d", &b);
    printf("%d %d\n", a, b);

    FILE* f = fopen(argp[1], "a");

    scanf("%d", &a);
    fprintf(f, "%d", a);
    fclose(f);
}