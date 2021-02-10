#include<stdio.h>
int main()
{
int x[10],y,si,ei,num,i,k,mid,size;
size=10;
for(y=0;y<size;y++)
{
printf("Enter a number: ");
scanf("%d",&x[y]);
}

i=1;
while(i<size)
{
k=i;
si=0;
ei=i-1;
num=x[i];
while(si<=ei)
{
mid=si+((ei-si)/2);
if(num==x[mid])
{
si=mid;
break;
}
else
if(num<x[mid])
{
ei=mid-1;
}
else
{
si=mid+1;
}
}
while(k>si)
{
x[k]=x[k-1];
k--;
}
x[si]=num;
i++;
}

for(y=0;y<size;y++) printf("%d\n",x[y]);

return 0;
}