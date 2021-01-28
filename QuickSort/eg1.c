#include<stdio.h>
#include<string.h>
int main()
{
int x[5],y,stack[5][2],top,lb,ub,e,f,g,pp,size;
for(y=0;y<5;y++)
{
printf("Enter a number: ");
scanf("%d",&x[y]);
}
size=5;
top=size;

top--;
stack[top][0]=0;
stack[top][1]=4;

while(top!=size)
{
lb=stack[top][0];
ub=stack[top][1];
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
stack[top][0]=pp+1;
stack[top][1]=ub;
}
if(lb<pp-1)
{
top--;
stack[top][0]=lb;
stack[top][1]=pp-1;
}
}
for(y=0;y<5;y++)
{
printf("%d\n",x[y]);
}
return 0;
}