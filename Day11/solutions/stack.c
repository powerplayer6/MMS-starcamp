#include <stdio.h>

typedef struct mystack
{
    int *st_arr;
    int cnt;
    int cap;
} mystack;

void push(mystack *stack, int element)
{
    if(stack->cnt!=stack->cap)
    {
        stack->st_arr[stack->cnt++] = element;
    }
    else 
    {
        printf("Error!\n");
    }
    //stack->cnt++;
}

int pop(mystack *stack)
{
    return stack->st_arr[--stack->cnt];
}

void printStack(mystack stack)
{
    for(int i=0; i<stack.cnt; i++)
    {
        printf("%d", stack.st_arr[i]);
    }
    printf("\n");
}

int main()
{
    mystack stack;
    int arr[10];
    stack.cap=10;
    stack.cnt=0;
    stack.st_arr=arr;
    push(&stack, 5);
    push(&stack, 6);
    push(&stack, 7);
    printStack(stack);
    printf("%d\n", pop(&stack));
    printf("%d\n", pop(&stack));
    printf("%d\n", pop(&stack));
    return 0;
}