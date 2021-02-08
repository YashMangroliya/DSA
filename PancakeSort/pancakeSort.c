#include<stdio.h>
int main()
{
int x[10],y,size,largest,e,f,i,largestIndex,g;

for(y=0;y<10;y++)
{
printf("Enter a number: ");
scanf("%d",&x[y]);
}
size=10;
while(size>1)
{
largestIndex=0;
for(i=0;i<size;i++)
{
if(x[i]>x[largestIndex]) largestIndex=i;
}
if(largestIndex==size-1)
{
size--;
continue;
}
e=0;
f=largestIndex;
while(e<f)
{
g=x[e];
x[e]=x[f];
x[f]=g;
e++;
f--;
}
e=0;
f=size-1;
while(e<f)
{
g=x[e];
x[e]=x[f];
x[f]=g;
e++;
f--;
}
size--;
}


for(i=0;i<10;i++) printf("%d\n",x[i]);
return 0;
}
