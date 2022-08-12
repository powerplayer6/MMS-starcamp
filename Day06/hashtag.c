#include <stdio.h>
#pragma

struct Point
{
    int x;
    double y;
};

int main()
{
    #ifdef OS
    #if 1
     printf("Hello\n");
    #else
     printf("Bye bye\n");
    #endif
    #endif
    struct Point point;
    point.x=1;
    point.y=2.5;
    printf("x=%d\ny=%.2lf\n",point.x,point.y);
    #warning warning
    printf("%s\n", __FILE__);
    return 0;
}