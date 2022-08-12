#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ** matrix=malloc(5*sizeof(int*));

    if(NULL==matrix)
    {
        perror("Cant malloc");
        exit(-1);
    }

    for(int i=0; i<5; i++)
    {
        matrix[i]=malloc((i+1)*sizeof(int));
        if(NULL==matrix[i])
        {
            perror("Cant malloc");
            exit(-1);
        }
    }

    for(int i=0; i<5; i++)
    {
        for(int j=0; j<=i; j++)
        {
            matrix[i][j]=j+1;
        }
    }

    for(int i=0; i<5; i++)
    {
        for(int j=0; j<=i; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}