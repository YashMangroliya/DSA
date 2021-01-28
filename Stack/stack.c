#inlcude<stdio.h>
#include<stdlib.h>

typedef struct __stack_node
{
void *data;
struct __stack_node *next;
}StackNode;

typedef struct __stack
{
StackNode *top;
int size;
int elementSize;
}Stack;

void initStack(Stack *stack,int elementSize)
{
stack->top=NULL;
stack->size=0;
stack->elementSize=elementSize;
}

void push(Stack *stack,const void *data)
{
StackNode * t=(StackNode*)malloc(sizeof(StackNode));
void *nodeData=(void*)malloc(stack->elementSize);
memcpy(nodeData,data,stack->elementSize);
t->data=nodeData;
t->next=stack->top;
stack->top=t;
}

void pop(Stack *stack,void *data)
{
StackNode *t;
t=stack->top;
stack->top=stack->top->next;
stack->size--;
memcpy(data,(const void *)t->data,stack->elementSize);
free(t->data);
free(t);
}

int isEmpty(Stack *stack)
{
return stack->size==0;
}