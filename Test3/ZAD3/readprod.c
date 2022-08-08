#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 40

typedef struct Product{
    double old_price;
    double new_price;
    unsigned int id;
    char product_type;
    char product_name[99];
} Product;

void prarr(Product *prods)
{
    for(int i=0; i<LEN; i++)
    {
        printf("%u\t%.2lf\t%.2lf\t%c\t%s\n", prods->id, prods->old_price,
        prods->new_price, prods->product_type, prods->product_name);
        prods++;
    }
}

int main()
{
    FILE *f=fopen("prods.bin", "rb");
    Product arr[LEN];
    fread(arr, sizeof(Product), LEN, f);
    prarr(arr);
    fclose(f);
    return 0;
}