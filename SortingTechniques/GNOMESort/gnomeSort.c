#include<stdio.h>
int main()
{
int x[10],y,j,size,g;
y=0;
while(y<10)
{
printf("Enter a number: ");
scanf("%d",&x[y]);
y++;
}
size=10;
j=0;
while(j<size)
{
if(j==0) j++;
if(x[j]<x[j-1])
{
g=x[j];
x[j]=x[j-1];
x[j-1]=g;
j--;
}
else
{
j++;
}
}
for(y=0;y<size;y++) printf("%d\n",x[y]);
return 0;
}