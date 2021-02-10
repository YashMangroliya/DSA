#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct _stack_node
{
void *ptr;
struct _stack_node *next;
}StackNode;

typedef struct _stack
{
StackNode *top;
int elementSize;
int size;
}Stack;

void initStack(Stack *stack,int elementSize)
{
stack->top=NULL;
stack->elementSize=elementSize;
stack->size=0;
}

int push(Stack *stack,void *ptr)
{
if(stack==NULL) return 0;
StackNode *node=(StackNode*)malloc(sizeof(StackNode));
if(node==NULL) return 0;
if(ptr!=NULL)
{
node->ptr=(void*)malloc(stack->elementSize);
if(node->ptr==NULL)
{
free(node);
return 0;
}
memcpy(node->ptr,(const void *)ptr,stack->elementSize);
}
else
{
node->ptr=ptr;
}
node->next=stack->top;
stack->top=node;
stack->size++;
return 1;
}

int pop(Stack *stack,void *ptr)
{
if(stack==NULL) return 0;
if(ptr==NULL) return 0;
StackNode *node;
node=stack->top;
if(node==NULL) return 0;
if(node->ptr!=NULL)
{
memcpy(ptr,(const void *)node->ptr,stack->elementSize);
}
else
{
for(int j=0;j<stack->elementSize;j++)
{
*((char *)(ptr+j))=(char)0;
}
}
stack->top=stack->top->next;
if(node->ptr!=NULL)free(node->ptr);
free(node);
stack->size--;
return 1;
}

int isEmpty(Stack *stack)
{
return stack->size==0;
}


void merge(void *x,int es,int (*p2f)(void*,void*),int lb1,int ub1,int lb2,int ub2)
{
printf("%d  %d | %d %d\n",lb1,ub1,lb2,ub2);
int size1=ub1-lb1+1;
int size2=ub2-lb2+1;
int size=size1+size2;
void *tmp;
tmp=(void *)malloc(es*size);
int i1,i2,i3;
i1=lb1;
i2=lb2;
i3=0;
while(i1<=ub1 && i2<=ub2)
{
if(p2f(x+i1,x+i2)<0)
{
memcpy((tmp+i3),(const void*)(x+i1),es);
i1++;
}
else
{
memcpy((tmp+i3),(const void*)(x+i2),es);
i2++;
}
i3++;
}
while(i1<=ub1)
{
memcpy((tmp+i3),(const void*)(x+i1),es);
i3++;
i1++;
}
while(i2<=ub2)
{
memcpy((tmp+i3),(const void*)(x+i2),es);
i3++;
i2++;
}
i3=0;
i1=lb1;
while(i1<=ub1)
{
memcpy((x+i1),(const void*)(tmp+i3),es);
i3++;
i1++;
}
i2=lb2;
while(i2<=ub2)
{
memcpy((x+i2),(const void*)(tmp+i3),es);
i3++;
i2++;
}
free(tmp);
}
void mergeSort(void *x,int es,int (*p2f)(void*,void*),int lowerBound,int upperBound)
{
struct LBUB
{
int lb,ub;
};

Stack *stack1,*stack2;
int a,b,mid;
int lb1,ub1,lb2,ub2,lb3,ub3;
stack1=(Stack*)malloc(sizeof(Stack));
stack2=(Stack*)malloc(sizeof(Stack));
initStack(stack1,sizeof(struct LBUB));
initStack(stack2,sizeof(struct LBUB));
struct LBUB lbub;
lbub.lb=lowerBound;
lbub.ub=upperBound;
push(stack1,(void*)&lbub);
while(!isEmpty(stack1))
{
printf("1st loop\n");
pop(stack1,(void*)&lbub);
push(stack2,(void*)&lbub);
a=lbub.lb;
b=lbub.ub;
mid=(a+b)/2;
if(a<mid)
{
lbub.lb=a;
lbub.ub=mid;
push(stack1,(void*)&lbub);
}
if(mid+1<b)
{
lbub.lb=mid+1;
lbub.ub=b;
push(stack1,(void*)&lbub);
}
}

while(!isEmpty(stack2))
{
pop(stack2,(void*)&lbub);
lb1=lbub.lb;
ub2=lbub.ub;
int mid=(lb1+ub2)/2;
merge(x,es,p2f,lb1,mid,mid+1,ub2);
}
}
int intComparator(void *left,void*right)
{
int *a,*b;
a=(int*)left;
b=(int*)right;
return *a-*b;
}
int main()
{
int *x,y;
y=0;
x=(int*)malloc(sizeof(int)*10);
while(y<10)
{
printf("Enter a number: ");
scanf("%d",&x[y]);
y++;
}
mergeSort(x,sizeof(int),intComparator,0,9);
for(y=0;y<=9;y++)
{
printf("%d\n",x[y]);
}
return 0;
}