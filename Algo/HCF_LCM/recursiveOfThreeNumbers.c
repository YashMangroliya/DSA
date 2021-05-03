#include<stdio.h>
int findHCF(int num1,int num2)
{
if(num2==0) return num1;
int remainder=num1%num2;
num1=num2;
num2=remainder;
return findHCF(num1,num2);
}


int main()
{
int num1,num2,num3;
printf("Enter num1: ");
scanf("%d",&num1);
printf("Enter num2: ");
scanf("%d",&num2);
printf("Enter num3: ");
scanf("%d",&num3);

printf("HCF of %d, %d and %d is %d",num1,num2,num3,findHCF(findHCF(num1,num2),num3));
return 0;
}