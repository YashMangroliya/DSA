// We have given a array and we have to find subarray, sum of the elements of this
//               subarray is equal to given 'requiredSum'.
//  This solution is 'Sliding Window' solution and it is for NON-NEGATIVE numbers;
#include<stdio.h>
int main()
{
int x[7]={7,15,3,12,7,4,15};
int requiredSum=15;
int si,ei;
si=0;
ei=0;
int sum=x[0];
while(ei<7)
{
if(sum<requiredSum)
{
ei++;
sum+=x[ei];
}
else if(sum>requiredSum)
{
sum-=x[si];
si++;
}
if(sum==requiredSum)
{
printf("Starting index: %d, Ending index: %d",si,ei);
break;
}
}
return 0;
}