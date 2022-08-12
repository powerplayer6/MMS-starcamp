#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    long data;
    struct Node* next;
} node;

void printNode(node* nod)
{
    node temp = *nod;
    printf("%ld ", temp.data);
    do
    {
        temp = *temp.next;
        printf("%ld ", temp.data);
    }
    while(temp.next!=NULL);
    printf("\n");
}

void pushBack(node* head, long newdata)
{
    node *new_node=malloc(sizeof(node));
    if(!new_node)
    {
        printf("Push back: could not malloc\n");
        exit -1;
    }
    new_node->data=newdata;
    new_node->next=NULL;
    node *last_node;
    while(head->next!=NULL)
    {
        head=head->next;
    }
    last_node=head;
    last_node->next = new_node;
}

void freeNode(node *head)
{
    if(head->next!=NULL)
    {
        freeNode(head->next);
    }
    free(head);
}

node *head1;

void popFront()
{
    node* tmp;
    tmp = head1;
    head1=head1->next;
    free(tmp);
}

void push_front(node** head_pp, long new_data)
{
    node* new_node = malloc(sizeof(node));
    if(!new_node)
    {
        perror("Malloc failed\n");
        exit(-1);
    }
    new_node->data=new_data;
    new_node->next=*head_pp;
    *head_pp=new_node;
}

void pop_back(node** head_pp)
{
    node *sl_node, *l_node;
    sl_node->next=NULL;
    freeNode(l_node);
    
}

int main()
{
    //node* a = malloc(sizeof(node*));
    /*node* b = malloc(sizeof(node*));
    node* c = malloc(sizeof(node*));
    node* d = malloc(sizeof(node*));
    head1 = malloc(sizeof(node*));
    head1->data=1;
    head1->next=b;
    b->data=2;
    b->next=c;
    c->data=3;
    c->next=d;
    d->data=4;
    d->next=NULL;
    pushBack(head1, 5);
    printNode(head1);
    //freeNode(head1);
    popFront();
    printNode(head1);
    freeNode(head1);*/

    node* head_linked_list_1 = NULL;

    push_front(&head_linked_list_1, 999);
    pushBack(head_linked_list_1, 100);
    pushBack(head_linked_list_1, 200);
    pushBack(head_linked_list_1, 300);
    push_front(&head_linked_list_1, 1);
    push_front(&head_linked_list_1, 2);
    printNode(head_linked_list_1);

    return 0;
}