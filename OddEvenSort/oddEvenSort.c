#include<stdio.h>
int main()
{
int x[10],y,size,swapCount,e,f,g;
size=10;
y=0;
while(y<size)
{
printf("Enter a number: ");
scanf("%d",&x[y]);
y++;
}
swapCount=1;
while(swapCount)
{
swapCount=0;
e=1;
f=2;
while(f<size)
{
if(x[f]<x[e])
{
g=x[e];
x[e]=x[f];
x[f]=g;
swapCount=1;
}
e+=2;
f+=2;
}
e=0;
f=1;
while(f<size)
{
if(x[f]<x[e])
{
g=x[e];
x[e]=x[f];
x[f]=g;
swapCount=1;
}
e+=2;
f+=2;
}
}

for(y=0;y<size;y++) printf("%d\n",x[y]);
return 0;
}