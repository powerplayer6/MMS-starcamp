#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int yesset(const char* s){
    int count = 0;
    while(*s != '\0'){
        for(int i=7; i>=0; --i){
            if((*s & (1 << i)) == 1) count++;
        }
        s++;
    }
    return count;
}

int main(int argc, char* argv[])
{
    char buff[99999];
    int mask, sum;
    for(int i=1; i<argc; i++)
    {
        sum=0;
        FILE *fp = fopen(argv[i], "rb");
        if(fp==NULL)
        {
            printf("%s - error!\n", argv[i]);
        }
        else
        {
            while(fgets(buff, 99, fp)!=NULL){}
            sum=yesset(buff);
            printf("%s - %d\n", argv[i], sum);
        }
    }
    return 0;
}