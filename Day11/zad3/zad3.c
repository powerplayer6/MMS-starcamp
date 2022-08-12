#include <stdio.h>
#include <string.h>

int main()
{
    char str[500];
    char str2[500]="";
    scanf("%s", &str);
    printf("%s\n", str);
    for(int i=0; i<strlen(str);i++)
    {
        if(i%2==0)
        {
            switch(str[i])
            {
                case '0':
                    strncat(str2, "A", 1);
                    break;
                case '1':
                    strncat(str2, "B", 1);
                    break;
                case '2':
                    strncat(str2, "C", 1);
                    break;
                case '3':
                    strncat(str2, "D", 1);
                    break;
                case '4':
                    strncat(str2, "E", 1);
                    break;
                case '5':
                    strncat(str2, "F", 1);
                    break;
                case '6':
                    strncat(str2, "G", 1);
                    break;
                case '7':
                    strncat(str2, "H", 1);
                    break;
                case '8':
                    strncat(str2, "I", 1);
                    break;
                case '9':
                    strncat(str2, "J", 1);
                    break;
                default:
                    break;
            }
        } else if (i%2!=0)
        {
            switch(str[i])
            {
                case '0':
                    strncat(str2, "!", 1);
                    break;
                case '1':
                    strncat(str2, "#", 1);
                    break;
                case '2':
                    strncat(str2, "/", 1);
                    break;
                case '3':
                    strncat(str2,"~", 1);
                    break;
                case '4':
                    strncat(str2, "=", 1);
                    break;
                case '5':
                    strncat(str2, "\'", 1);
                    break;
                case '6':
                    strncat(str2, "\\", 1);
                    break;
                case '7':
                    strncat(str2, ">", 1);
                    break;
                case '8':
                    strncat(str2, ".", 1);
                    break;
                case '9':
                    strncat(str2, ",", 1);
                    break;
                default:
                    break;
            }
        }
    }
    printf("%s\n",str2);
    return 0;
}