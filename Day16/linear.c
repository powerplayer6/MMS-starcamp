#include <stdio.h>
#include <getopt.h>
#include <math.h>

int main(int argc, char* argv[])
{
    double x1 = 0, x2=0, a, b, c;
    int opt;

    while ((opt=getopt(argc, argv, "a:b:c:"))!=-1)
    {
        switch(opt)
        {
            case 'a':
                sscanf(optarg, "%lf", &a);
                break;
            case 'b':
                sscanf(optarg, "%lf", &b);
                break;
            case 'c':
                sscanf(optarg, "%lf", &c);
                break;
            default:
                break;
        }
    }
    x1=(-b+sqrt(b*b-4*a*c))/(2*a);
    x2=(-b-sqrt(b*b-4*a*c))/(2*a);
    printf("x1 = %.2lf\nx2 = %.2lf\n", x1, x2);
    return 0;
}