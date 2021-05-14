#include<stdio.h>
int main()
{
int x[5]={3,5,2,4,3};
int e,f,startPoint,sum,rSum,size,count;
size=5;
count=0;
e=0;
f=1;
rSum=7;
startPoint=0;
sum=x[e]+x[f];
while(f<size)
{
printf("e: %d, f: %d\n",e,f);

if(sum==rSum)
{
//printf("e: %d, f: %d\n",e,f);
if(e+1==f)count++;
f++;
sum+=x[f];
}
if(sum>rSum)
{
sum-=x[e];
e++;
}
else 
{
f++;
sum+=x[f];
}
}

printf("%d",count);
return 0;
}