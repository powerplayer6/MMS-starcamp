#include <stdio.h>
int main()
{
    float num1=1234567.12345f;
    printf("%.20f\n",num1);
    printf("%lu\n",sizeof(num1));
    double num2=1234567.12345;
    printf("%.20lf\n",num2);
    printf("%lu\n",sizeof(num2));

}