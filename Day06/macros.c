#include <stdio.h>
#define SETBIT(mask, bit) mask |= (1ULL << (bit))
#include <stdbool.h>
#define PRINTNUM(n) printf("%d\n", num##n)

int main()
{
    int num2=3;
    PRINTNUM(2);
    return false;
}