#include<stdio.h>
int kthSmallest(int *x,int kk,int size)
{
int swapCount,i,j,g;
int k=kk-1;
while(1)
{
swapCount=0;
i=0;
while(i<k)
{
if(x[i]>x[k])
{
swapCount++;
g=x[i];
x[i]=x[k];
x[k]=g;
break;
}
i++;
}
j=size-1;
while(j>k)
{
if(x[j]<x[k])
{
swapCount++;
g=x[j];
x[j]=x[k];
x[k]=g;
break;
}
j--;
}
if(swapCount==0) break;
}
return x[k];
}
int main()
{
int x[10]={45,22,48,562,3,147,41,29,60,10};
int num=kthSmallest(x,5,10);
printf("kth smallest is: %d",num);
return 0;
}