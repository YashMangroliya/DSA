// here we will be finding the length of LIS (Longest increasing sub sequence)
#include<stdio.h>
int main()
{
int x[9]={12,3,92,-3,76,93,54,12,78};
int counter[9]={1,1,1,1,1,1,1,1,1};
int e,f,count;
count=0;
f=1;
while(f<=8)
{
e=0;
while(e<f)
{
if(x[e]<x[f])
{
if(counter[e]+1>counter[f])
{
counter[f]=counter[e]+1;
if(count<counter[f]) count=counter[f];
}
}
e++;
}
f++;
}

printf("Length of longest increasing sub sequence is %d",count);
return 0;
}