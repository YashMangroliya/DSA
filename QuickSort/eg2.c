#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
int *x,y,*stack,top,lb,ub,e,f,g,pp,size,req;
printf("Enter requirement: ");
scanf("%d",&req);
x=(int*)malloc(sizeof(int)*req);
stack=(int*)malloc(sizeof(int)*req*2);
for(y=0;y<req;y++)
{
printf("Enter a number: ");
scanf("%d",&x[y]);
}
size=req;
top=size;

top--;
*(stack+(top*2+0))=0;
*(stack+(top*2+1))=top;

while(top!=size)
{
lb=*(stack+(top*2+0));
ub=*(stack+(top*2+1));
top++;
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
pp=f;
if(pp+1<ub)
{
top--;
*(stack+(top*2+0))=pp+1;
*(stack+(top*2+1))=ub;
}
if(lb<pp-1)
{
top--;
*(stack+(top*2+0))=lb;
*(stack+(top*2+1))=pp-1;
}
}
for(y=0;y<req;y++)
{
printf("%d\n",x[y]);
}
return 0;
}