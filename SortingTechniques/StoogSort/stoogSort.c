#include<stdio.h>
#include<stdlib.h>
void stoogSort(int *x,int lb,int ub);
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

int main()
{
int x[10],y,size,lb,ub,g,subSize;
Stack lbStack;
Stack ubStack;
initStack(&lbStack);
initStack(&ubStack);
size=10;
push(&lbStack,0);
push(&ubStack,size-1);
for(y=0;y<size;y++)
{
printf("Enter a number: ");
scanf("%d",&x[y]);
}
while(isEmpty(&lbStack)==0 && isEmpty(&ubStack)==0)
{
lb=pop(&lbStack);
ub=pop(&ubStack);
printf("lb:%d, ub%d\n",lb,ub);
if(x[lb]>x[ub])
{
g=x[lb];
x[lb]=x[ub];
x[ub]=g;
}
size=ub-lb+1;
subSize=size-(size/3);
if(size>2)
{
push(&lbStack,lb);
push(&ubStack,lb+subSize-1);

push(&lbStack,ub-subSize+1);
push(&ubStack,ub);

push(&lbStack,lb);
push(&ubStack,lb+subSize-1);
}
}
for(y=0;y<10;y++)
{
printf("%d\n",x[y]);
}
return 0;
}