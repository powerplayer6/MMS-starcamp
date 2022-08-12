#include <stdio.h>

typedef struct Queue{
    int cnt;
    char* quarr;
    int cap;
} queue;

void myPush(queue* q, char elem)
{
    if(q->cnt!=q->cap)
    {
        q->quarr[q->cnt++] = elem;
    }
    else
    {
        printf("Error!\n");
    }
}

void priQue(queue q)
{
    for (size_t i = 0; i < q.cnt; i++)
    {
        printf("%c ",q.quarr[i]);
    }
    printf("\n");
}

char myPop(queue *q)
{
    char temp = q->quarr[0];
    for (size_t i = 0; i < q->cnt; i++)
    {
        q->quarr[i]=q->quarr[i+1];
    }
    return temp;
}

int main()
{
    queue opash;
    char arr[10];
    opash.quarr=arr;
    opash.cap=10;
    opash.cnt=0;
    myPush(&opash, 'a');
    myPush(&opash, 'b');
    myPush(&opash, 'c');
    myPush(&opash, 'd');
    myPush(&opash, 'e');
    priQue(opash);
    printf("%c\n", myPop(&opash));
    priQue(opash);
    return 0;
}