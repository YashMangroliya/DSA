// In this example, I will create a program to find subsequences of an array.
// (With a better Time Complexity)

#include<stdio.h>
#include<math.h>
int main()
{
int x[4]={1,2,3,4};
int e,j,num,xEP,lenX,upperBound;
lenX=4;
upperBound=lenX-1;
xEP=pow(2,lenX)-1;

num=1;
while(num<=xEP)
{
for(e=upperBound;e>=0;e--)
{
j=num>>e;
if(j&1) printf("%d ",x[upperBound-e]);
}
printf("\n");
num++;
}
return 0;
}