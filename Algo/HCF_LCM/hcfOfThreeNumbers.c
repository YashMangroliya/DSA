#include<stdio.h>
int main()
{
int num1,num2,num3,n1,n2,n3;
printf("Enter num1: ");
scanf("%d",&num1);
printf("Enter num2: ");
scanf("%d",&num2);
printf("Enter num3: ");
scanf("%d",&num3);
n1=num1;
n2=num2;
n3=num3;
int remainder;
while(num2!=0)
{
remainder=num1%num2;
num1=num2;
num2=remainder;
}
while(num3!=0)
{
remainder=num1%num3;
num1=num3;
num3=remainder;
}
printf("HCF of %d and %d and %d is %d",n1,n2,n3,num1);
}