#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char* argv[])
{
    double arr[99999], arr2[99999], tmp;
    int c, i=0;
    char ivalue[100]="";
    char ovalue[100]="";
    while((c=getopt(argc, argv, "i:o:"))!=-1)
    {
        switch(c)
        {
            case 'i':
                //ivalue=optarg;
                strcpy(ivalue, optarg);
                break;
            case 'o':
                //ovalue=optarg;
                strcpy(ovalue, optarg);
                break;
            default:
                exit(-1);
                break;
        }
    }
    FILE* f = fopen(ivalue, "r");
    FILE* f2 = fopen(ovalue, "w");
    while(fscanf(f, "%lf", &arr[i]) != EOF) {
        i++; 
    }

    for(int j=0; j<i; j++)
    {
        printf("%lf ", arr[j]);
    }
    printf("\n");

    //tmp = arr[0];
    for(int j=0; j<i; j++)
    {
        for(int l=j+1; l<i; l++)
        {
            if(arr[j]>arr[l])
            {
                tmp=arr[j];
                arr[j]=arr[l];
                arr[l]=tmp;
            }
        }
    }

    printf("\n");
    for(int j=0; j<i; j++)
    {
        printf("%lf ", arr[j]);
    }
    printf("\n");

    for(int j=0; j<i; j++)
    {
        fprintf(f2, "%.2lf\n", arr[j]);
    }

    fclose(f);
    fclose(f2);

    return 0;
}