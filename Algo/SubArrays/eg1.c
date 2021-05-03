// We have given a array and we have to find subarray, sum of the elements of this
//               subarray is equal to given 'requiredSum'.

#include<stdio.h>
int main()
{
int x[6]={-10,7,2,-1,4,-6};
int requiredSum=-1,sum;
int i,j;
i=0;
while(i<6)
{
j=i;
sum=0;
while(j<6)
{
sum+=x[j];
if(sum==requiredSum)
{
printf("Starting index: %d, Ending index: %d",i,j);
return 0;
}
j++;
}
i++;
}


return 0;
}