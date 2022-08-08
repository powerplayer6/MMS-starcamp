#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *buff;
    FILE *f = fopen(argv[1], "rb");
    fseek(f, 0, SEEK_END);  
    long len = ftell(f);
    rewind(f);
    buff = (char*)malloc(len*sizeof(char));
    fread(buff, len, 1, f);
    printf("%s\n", buff);

    if(strcmp(argv[2], "-H")==0)
    {
        for(int i=0; i<strlen(buff); i++)
        {
            printf("%02X ", buff[i]);
        }
        printf("\n");
    } else if(strcmp(argv[2], "-B")==0)
    {
        for(int i=0; i<strlen(buff); i++)
        {
            //for(int j=0; j<8; j++)
            for(int j=7; j>=0; j--)
            {
                printf("%d", (buff[i]>>j)&1);
            }
            printf(" ");
        }
        printf("\n");
    }
    fclose(f);
    return 0;
}