#include <stdio.h>
#include <stdint.h>

int main()
{
    uint64_t attendance = 0;
    int option;
    int bit;
    while(1)
    {
        printf("1.Set attend\n2.Clear attend\n3.Info\n4.Change attend\n5.Exit\n");
        scanf("%d",&option);
        if (option==1)
        {
            printf("Student number (0-63): ");
            scanf("%d",&bit);
            attendance=attendance|(1ULL<<bit);
        } else if (option==2)
        {
            printf("Student number (0-63): ");
            scanf("%d",&bit);
            attendance=attendance&~(1ULL<<bit);
        } else if (option==3)
        {
            printf("Student number (0-63): ");
            scanf("%d",&bit);
            printf("%d\n",!!(attendance&(1ULL<<bit)));
        } else if (option==4)
        {
            printf("Student number (0-63): ");
            scanf("%d",&bit);
            attendance ^= 1ULL << bit;
            
        } else if (option==5)
        {
            break;
        }
    }
    return 0;
}