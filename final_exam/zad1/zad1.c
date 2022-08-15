#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <string.h>
#define LAPTOPS_COUNT 15

typedef struct Laptop
{
    uint64_t snumber;
    char brand[100];
    double weight;
    double price;
} Laptop;

int randint(int lower, int upper)
{
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

double randbl(double min, double max) 
{
    double range = (max - min); 
    double div = RAND_MAX / range;
    return min + (rand() / div);
}

void printTop(Laptop* laps, int cnt)
{
    for(int i=0; i<cnt; i++)
    {
        printf("Serial number: %d\tBrand: %s\t\tPrice %lf EUR\tWeight: %lf KG\n",
                laps[i].snumber, laps[i].brand, laps[i].price, laps[i].weight);
    }
}

double totalLaptopWeight(Laptop *laps)
{
    double sum=0;
    for(int i=0; i<LAPTOPS_COUNT; i++)
    {
        sum=sum+laps[i].weight;
    }
    return sum;
}

Laptop *minPriceItem(Laptop* laps)
{
    double lp=laps[0].price;
    int flag=0;
    for(int i=0; i<LAPTOPS_COUNT; i++)
    {
        if (lp>laps[i].price)
        {
            lp=laps[i].price;
            flag=i;
        }
    }
    return &laps[flag];
}

int main()
{
    char buff[99]="";
    int namelen = 0;
    int temp, j;
    srand(time(NULL));
    Laptop* laptops = malloc(sizeof(Laptop)*LAPTOPS_COUNT);
    for(int i = 0; i<LAPTOPS_COUNT; i++)
    {
        laptops[i].snumber=i;
        laptops[i].price=randbl(10.0, 5000.0);
        laptops[i].weight=randbl(0.025, 10.0);
        j=0;
        int namelen = randint(8, 12);
        while(j<namelen)
        {
            if(j==0)
            {
                temp=randint(65, 90);
            }
            else
            {
                temp=randint(97, 122);
            }
            strncat(buff, &temp, 1);
            //printf("%s %d\n", buff, j);
            j++;
        }
        strcpy(laptops[i].brand, buff);
        memset(buff, 0, sizeof(buff));
    }
    printTop(laptops, LAPTOPS_COUNT);
    printf("\nTotal weight: %lf KG\n", totalLaptopWeight(laptops));
    printf("\nCheapest laptop:\n");
    printTop(minPriceItem(laptops), 1);
    printf("\n");
    return 0;
}