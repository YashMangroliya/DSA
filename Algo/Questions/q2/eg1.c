// Given an array having numbers from 0 to n, but 1 number is missing 
// we have to find that missing number
// prerequisite:
// sum of n natural numbers(i.e. 0->n or 1->n):  n(n+1)/2
#include<stdio.h>
int getMissingNumber(int *numbers,int n) // here n represent that array was supposed to contains numbers from 0 to 'n', but 1 number is missing
{
int sum1,sum2,i;
sum1=n*(n+1)/2;
sum2=0;
for(i=0;i<n;i++) sum2+=numbers[i];
return sum1-sum2;
}
int main()
{
int x[6]={3,5,1,4,0,6};
printf("Missing number: %d\n",getMissingNumber(x,6));
return 0;
}