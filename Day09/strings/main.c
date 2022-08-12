#include <stdio.h>
#include <string.h>

size_t mystrlen(const char* str)
{
    size_t cnt=0;
    while(str[cnt]!='\0')
    {
        cnt++;
    }
    return cnt++;
}

int mystrcmp(const char* str1, const char* str2)
{
    int flag=0;
    if(strlen(str1)!=strlen(str2))
    {
        return -1;
    } else
    for (size_t i = 0; i < strlen(str1); i++)
    {
        if(str1[i]!=str2[i])
        {
            flag=-1;
        }
    }
    
    return flag;
}

int main()
{
    /*char str[]="Hello World";
    printf("%s\n", str);

    char str2[]={'a', 'b', 'c', '\0'};
    printf("%c\n", *str2);
    printf("%lu\n",mystrlen(str));

    char name[100];
    strcpy(name, "Pesho");
    printf("%s\n", name);*/

    //char name1[101];
    //scanf("%s", name1);
    //fgets(name1,100, stdin);
    //name1[strlen(name1)-1]="\0";
    //char name2[5];
    //strncpy(name1, "Alexander",4);
    //strncpy(name2, "Alex",4) ;
    //printf("%s\n", name1);
    //printf("%s\n", name2);


    char str1[]="string";
    char str2[]="strings";
    printf("%d\n",mystrcmp(str1, str2));
    
    return 0;
}