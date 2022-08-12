#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Product{
    unsigned int id;
    float price;
    unsigned short sales;
    char name[10];
};

//int idcnt=0;

char *names[]=
{
    "product1",
    "product2",
    "product3",
    "product4",
    "product5"
};

void init_rnd_prod(struct Product *p)
{
    static int idcnt = 0;
    p->id=idcnt++;
    p->price = (150+rand()%(20025-150))/100;
    p->sales=rand()%1000;
    p->name;
    strcpy(p->name, names[rand()%5]);
}

void prpr(struct Product *p)
{
    printf("Revenue: %f\tID: %d\tPrice: %f\tSales: %d\tName: %s\n", p->price*p->sales, p->id, p->price,p->sales,p->name);
}

/*int prodcump(struct Product *p)
    {
        if((p->sales*p->price) != ((p+1))->sales*((p+1))->price)
        {
            if((p->sales*p->price) > ((p+1))->sales*((p+1))->price)
            {
                return 1;
            } else return -1;
        } 

        else if (p->name!=(p+1)->name)
        {
            return strncmp(p->name, (p+1)->name, 10);
        }

        else if (p->id>(p+1)->id)
        {
            return 1;
        } else return -1;
        return 0;
    }*/

int prodcomp(struct Product *p, struct Product *p2)
    {
        if((p->sales*p->price) != p2->sales*p2->price)
        {
            if((p->sales*p->price) > p2->sales*p2->price)
            {
                return 1;
            } else return -1;
        } 

        else if (p->name!=p2->name)
        {
            return strncmp(p->name, p2->name, 10);
        }

        else if (p->id > p2->id)
        {
            return 1;
        } else return -1;
        return 0;
    }

int main()
{
    srand(time(0));
    struct Product *prod;
    prod=malloc(30*sizeof(struct Product));
    if(!prod)
    {
        printf("Malloc failed");
        return -1;
    }
    srand(time(NULL));
    for(int i=0; i<30;i++)
    {
        init_rnd_prod(prod+i);
    }

    qsort(prod, 30, sizeof(struct Product), prodcomp);

    
    for(int i=0; i<30;i++)
    {
        prpr(prod+i);
    }
    return 0;
}