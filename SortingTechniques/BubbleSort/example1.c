#include<stdio.h>
#include<stdlib.h>
void bubbleSort(int* x,int size)
{
int m,e,f,g;
m=size-2;
while(m>=0)
{
e=0;
f=1;
while(e<=m)
{
if(x[f]<x[e])
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
e++;
f++;
}
m--;
}
}
int main()
{
int j,y;
int *x;
printf("Enter your requirements: \n");
scanf("%d",&j);
x=(int *)malloc(sizeof(int)*j);
for(y=0;y<j;y++)
{
printf("Enter a number: ");
scanf("%d",&x[y]);
}
bubbleSort(x,j);
for(y=0;y<j;y++)
{
printf("%d\n",x[y]);
}
return 0;
}