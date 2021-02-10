#include<stdio.h>
#include<stdlib.h>
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

void quickSort(int *x,int lb,int ub)
{
if(lb>=ub) return;
int pp=findPartitionPoint(x,lb,ub);
quickSort(x,lb,pp-1);
quickSort(x,pp+1,ub);
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