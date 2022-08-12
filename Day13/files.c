#include <stdio.h>

int main(int argc, char *argp[])
{
    FILE* f = fopen(argp[1], "r");
    if(f==NULL)
    {
        printf("Error!");
        return 0;
    }
    fseek(f, 0, SEEK_END);
    int symbol_count = ftell(f);
    int cur_sym;
    fseek(f, symbol_count/2, SEEK_SET);
    /*while(cur_sym=fgetc(f)!=EOF)
    {
        printf("%c", cur_sym);
    }*/


    cur_sym = fgetc(f);
    do
    {
        printf("%c", cur_sym);
        cur_sym = fgetc(f);
    } while(cur_sym!=EOF);
    printf("\n");
    
    
    

    fclose(f);
    return 0;
}