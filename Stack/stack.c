#inlcude<stdio.h>
#include<stdlib.h>
typedef struct __stack_node
{
int data;
struct __stack_node  *next;
}StackNode;

typedef struct __stack
{
StackNode *top;
int size;
}Stack;

void initStack(Stack *stack)
{
stack->top=NULL;
stack->size=0;
}

void push(Stack* stack,int num)
{
StackNode *t;
t=(StackNode*)malloc(sizeof(StackNode));
t->data=num;
t->next=stack->top;
stack->top=t;
stack->size=stack->size+1;
}

int pop(Stack *stack)
{
StackNode *t;
int data;
data=stack->top->data;
t=stack->top;
stack->top=stack->top->next;
free(t);
stack->size--;
return data;
}

int isEmpty(Stack *stack)
{
return stack->size==0;
}
