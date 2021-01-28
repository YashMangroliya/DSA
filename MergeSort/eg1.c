#include<stdio.h>
#include<stdlib.h>
typedef struct _stack_node
{
int lb,ub;
struct _stack_node *next;
}StackNode;

typedef struct _stack
{
StackNode *top;
int size;
}Stack;

void initStack(Stack *stack)
{
stack->top=NULL;
stack->size=0;
}

void push(Stack *stack,int lb,int ub)
{
StackNode *stackNode;
stackNode=(StackNode*)malloc(sizeof(StackNode));
stackNode->lb=lb;
stackNode->ub=ub;
stackNode->next=stack->top;
stack->top=stackNode;
stack->size++;
}
void pop(Stack *stack,int *lb,int *ub)
{
StackNode *t;
t=stack->top;
stack->top=stack->top->next;
*lb=t->lb;
*ub=t->ub;
free(t);
stack->size--;
}
int isEmpty(Stack *stack)
{
return stack->size==0;
}
int main()
{
int x[10],y,tmp[10];
Stack *stack1,*stack2;
int a,b,mid;
int lb1,ub1,lb2,ub2,lb3,ub3;
int i1,i2,i3;
y=0;
while(y<10)
{
printf("Enter a number: ");
scanf("%d",&x[y]);
y++;
}

stack1=(Stack*)malloc(sizeof(Stack));
stack2=(Stack*)malloc(sizeof(Stack));
initStack(stack1);
initStack(stack2);
push(stack1,0,9);
while(!isEmpty(stack1))
{
printf("1st loop\n");
pop(stack1,&a,&b);
push(stack2,a,b);
mid=(a+b)/2;
if(a<mid)
{
push(stack1,a,mid);
}
if(mid+1<b)
{
push(stack1,mid+1,b);
}
}

StackNode *tt=stack2->top;
while(tt!=NULL)
{
printf("%d  %d\n",tt->lb,tt->ub);
tt=tt->next;
}

while(!isEmpty(stack2))
{
pop(stack2,&lb1,&ub2);
ub1=(lb1+ub2)/2;
lb2=ub1+1;
lb3=lb1;
ub3=ub2;
printf("%d  %d | %d %d\n",lb1,ub1,lb2,ub2);
i1=lb1;
i2=lb2;
i3=lb3;
while(i1<=ub1 && i2<=ub2)
{
if(x[i1]<x[i2])
{
tmp[i3]=x[i1];
i1++;
}
else
{
tmp[i3]=x[i2];
i2++;
}
i3++;
}
while(i1<=ub1)
{
tmp[i3]=x[i1];
i3++;
i1++;
}
while(i2<=ub2)
{
tmp[i3]=x[i2];
i3++;
i2++;
}
i3=lb3;
while(i3<=ub3)
{
x[i3]=tmp[i3];
i3++;
}
}

for(y=0;y<=9;y++)
{
printf("%d\n",x[y]);
}
return 0;
}