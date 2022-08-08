#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

struct Node* cll = NULL;

void fill()
{
    int num;
    struct Node *tmp = malloc(sizeof(Node));
    printf("Input number: \n");
    scanf("%d", &num);
    if(cll==NULL)
    {
        tmp->data=num;
        tmp->next=tmp;
        cll = tmp;
    } else
    {
        tmp->data=num;
        tmp->next=cll->next;
        cll->next=tmp;
    }
}

void printCLL(Node *cyc)
{
    if(cyc==NULL)
    {
        printf("Empty list");
    } else
    {
        Node* tmp;
        tmp = cyc->next;
        do
        {
            printf("%d\t", tmp->data);
            tmp = tmp->next;
        } while (tmp!=cyc->next);
        printf("\n");
    }
}

Node* insertAfter(Node* cyc, int cnt, int newDa)
{
    Node *tmp = cyc->next;
    Node *prv = cyc;
    Node *newEl = malloc(sizeof(Node));
    for(int i=0; i<cnt; i++)
    {
        tmp=tmp->next;
        prv=prv->next;
    }
    newEl->data=newDa;
    newEl->next=tmp;
    prv->next=newEl;
    return newEl;
}

int main()
{
    int len;
    printf("Input length: \n");
    scanf("%d", &len);
    for(int i=0; i<len; i++)
    {
        fill();
    }
    printCLL(cll);
    insertAfter(cll, 3, 69);
    printCLL(cll);
    return 0;
}