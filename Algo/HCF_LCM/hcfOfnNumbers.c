#include<stdio.h>
int main()
{
int req,i,num1,num2,remainder;
printf("Enter requirement: ");
scanf("%d",&req);
int nums[req];
i=0;
while(i<req)
{
printf("Enter number: ");
scanf("%d",&nums[i]);
i++;
}
i=0;
int j=1;
num1=nums[i];
num2=nums[j];
while(j<req)
{
num2=nums[j];
while(num2!=0)
{
remainder=num1%num2;
num1=num2;
num2=remainder;
}
j++;
}

printf("HCF of above %d numbers is: %d",req,num1);
//printf("HCF of %d and %d and %d is %d",n1,n2,n3,num1);
}