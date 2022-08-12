#include <stdio.h>

typedef struct Queue{
    int begin, end;
    char* quarr;
    int cap;
} queue;

int getFirst(queue *q)
{
    return q->quarr[q->begin];
}

void push(queue *q, char elem)
{
    q->quarr[q->end]=elem;
    q->end++;
}

void pop(queue *q)
{
    q->begin++;
}

void printBuf(queue *q)
{
    printf("BEGIN: %d\nEND: %d\n", q->begin, q->end);
    for(int i=0; i<q->cap; i++)
    {
        printf("%c ", q->quarr[i]);
    }
    printf("\n");
}

int main()
{
    queue opash;
    char arr[10];
    opash.quarr=arr;
    opash.cap=10;
    opash.begin=0;
    opash.end=0;
    push(&opash, 'a');
    push(&opash, 'b');
    push(&opash, 'c');
    push(&opash, 'd');
    push(&opash, 'e');
    printBuf(&opash);
    printf("%c\n",getFirst(&opash));
    pop(&opash);
    printBuf(&opash);
    return 0;
}