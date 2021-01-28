#include<stdio.h>
#include<stdlib.h>
struct Node
{
int lb,ub;
struct Node *next;
};
struct Node * top=NULL;
int findPartitionPoint(int *x,int lb,int ub)
{
int pp,e,f,g;
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
g=x[f];
x[f]=x[lb];
x[lb]=g;
}
}
return f;
}
void push(int lb,int ub)
{
struct Node *t=(struct Node*)malloc(sizeof(struct Node));
t->lb=lb;
t->ub=ub;
t->next=top;
top=t;
}
void quickSort(int *x,int lowerBound,int upperBound)
{
int lb,ub,e,f,pp;
push(lowerBound,upperBound);
struct Node * t;
while(top!=NULL)
{
lb=top->lb;
ub=top->ub;
t=top;
top=top->next;
free(t);
pp=findPartitionPoint(x,lb,ub);
if(pp+1<ub)push(pp+1,ub);
if(lb<pp-1)push(lb,pp-1);
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
free(x);
return 0;
}