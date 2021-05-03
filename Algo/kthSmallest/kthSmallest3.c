#include<stdio.h>
int kthSmallest(int *x,int k,int size)
{
int e,f,g;
e=0;
while(e<k)
{
f=e+1;
while(f<size)
{
if(x[f]<x[e])
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
f++;
}
e++;
}
return x[k-1];
}
int main()
{
int x[10]={25,48,624,10,32,4,9,65,3,23};
int num=kthSmallest(x,5,10);
printf("%dth smallest is: %d",5,num);
return 0;
}