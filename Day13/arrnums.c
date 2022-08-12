#include <stdio.h>
int arr[]={100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
int arrc=10;

int main()
{
    FILE *f = fopen("arrfile", "w");
    if(f==NULL)
    {
        printf("Could not open");
        return -1;
    }
    for(int* i=arr; i<arr+arrc; i++)
    {
        fprintf(f, "%d", *i);
    }
    fclose(f);
}