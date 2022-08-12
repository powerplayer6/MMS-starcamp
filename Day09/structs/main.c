#include <stdio.h>

struct Point {
    double x;
    double y;
};

typedef struct Point point_t;

typedef struct {
    char title[100];
    char author[100];
    int pages;
    double price;
} book_t;

struct struct1 {
    double a;
    int b;
    char c;
};

struct struct2 {
    int b;
    double a;
    char c;
};

int main()
{
    point_t p1;
    point_t p2={3.2, 5.5};
    point_t p3={.x=4.4, .y=6.6};
    p1.x=4.2;
    p1.y=6.9;
    //printf("x=%.1lf, y=%.1lf\n", p1.x, p1.y);
    //printf("x=%.1lf, y=%.1lf\n", p2.x, p2.y);
    //printf("x=%.1lf, y=%.1lf\n", p3.x, p3.y);
    printf("%lu %lu\n", sizeof(struct struct1), sizeof(struct struct2));
    return 0;
}