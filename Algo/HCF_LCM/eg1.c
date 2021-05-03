#include<stdio.h>
int main()
{
int num1,num2,n1,n2;
printf("Enter num1: ");
scanf("%d",&num1);
printf("Enter num2: ");
scanf("%d",&num2);
n1=num1;
n2=num2;
int remainder;
while(num2!=0)
{
remainder=num1%num2;
num1=num2;
num2=remainder;
}
printf("HCF of %d and %d is %d",n1,n2,num1);
}