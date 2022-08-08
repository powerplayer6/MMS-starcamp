#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define LEN 40

typedef struct Product{
    double old_price;
    double new_price;
    unsigned int id;
    char product_type;
    char product_name[99];
} Product;

double randDBL(double min, double max)
{
    double range = (max-min);
    double div=RAND_MAX/range;
    return min+(rand()/div);
}

int randINT(int min, int max)
{
    int num;
    num=(rand() % (max - min + 1)) + min;
    return num;
}

int prodcomp(Product *p, Product *p2)
{
    double dif1=p->new_price - p->old_price;
    double dif2=p2->new_price - p2->old_price;
    char *t1=p->product_type;
    char *t2=p2->product_type;
    if(dif1 != dif2)
    {
        if(dif1>dif2)
        {
            return 1;
        } else return -1;
    } else if (t1!=t2)
    {
        return strncmp(t1, t2, 1);
    } else if (p->product_name != p2->product_name)
    {
        return !strcmp(p->product_name, p2-> product_name);
    } else if (p->id > p2->id)
    {
        return 1;
    } else return -1;
}

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
    srand(time(NULL));
    char *names[5]={"bob", "leshta", "lutenica", "domat", "salam"};
    char types[4]={'A', 'B', 'C', 'D'};
    Product arr[LEN];
    for(int i=0; i<LEN; i++)
    {
        arr[i].id=i;
        arr[i].old_price=randDBL(4.99, 100.45);
        arr[i].new_price=randDBL(4.99, 100.45);
        arr[i].product_type=types[randINT(0,3)];
        strcpy(arr[i].product_name, names[randINT(0,4)]);
    }
    prarr(arr);
    printf("\n");
    qsort(arr, LEN, sizeof(Product), prodcomp);
    prarr(arr);
    FILE *f = fopen("prods.bin", "wb");
    fwrite(arr, sizeof(Product), LEN, f);
    fclose(f);
    return 0;
}