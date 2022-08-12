#include <stdio.h>

int main(int argc, char *argp[])
{
    FILE* f = fopen(argp[1], "r");
    int cur_sym;
    char *word=argp[2];
    int wc=0, res=0;
    while((cur_sym=fgetc(f))!=EOF)
    {
        if(cur_sym==word[wc])
        {
            wc++;
        } else wc=0;
        if(word[wc]=='\0')
        {
            res++;
            wc=0;
        }
    }
    printf("%d\n", res);
}