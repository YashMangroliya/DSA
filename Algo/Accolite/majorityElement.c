#include<stdio.h>
int main()
{
int x[5]={4,1,3,4,4};
int size=5;
int i=0;
int majorityElement=x[0];
int count=1;
for(i=1;i<5;i++)
{
if(x[i]==majorityElement) count++;
else count--;
if(count==0) 
{
majorityElement=x[i];
count=1;
}
}
printf("%d\n",majorityElement);
}