#include<stdio.h>
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
int findPartitionPoint(int *x,int lb,int ub)
{
int e,f,g;
e=lb;
f=ub;
while(e<f)
{
while(e<ub && x[e]<=x[lb]) e++;
while(x[f]>x[lb]) f--;
if(e<f)
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
else
{
g=x[lb];
x[lb]=x[f];
x[f]=g;
}
}
return f;
}

void quickSort(int *x,int lowerBound,int upperBound)
{
int lb,ub,pp;
Stack *ubStack,*lbStack;
ubStack=(Stack*)malloc(sizeof(Stack));
lbStack=(Stack*)malloc(sizeof(Stack));
initStack(ubStack);
initStack(lbStack);
push(lbStack,lowerBound);
push(ubStack,upperBound);
while(!isEmpty(lbStack) && !isEmpty(ubStack))
{
lb=pop(lbStack);
ub=pop(ubStack);
pp=findPartitionPoint(x,lb,ub);
if(pp+1<ub)
{
push(lbStack,pp+1);
push(ubStack,ub);
}
if(lb<pp-1)
{
push(lbStack,lb);
push(ubStack,pp-1);
}
}
}

int main()
{
int *x,req,y;
printf("Enter requirement: ");
scanf("%d",&req);
x=(int*)malloc(sizeof(int)*req);
for(y=0;y<req;y++)
{
printf("Enter number: ");
scanf("%d",&x[y]);
}
quickSort(x,0,req-1);
for(y=0;y<req;y++)
{
printf("%d\n",x[y]);
}
return 0;
}