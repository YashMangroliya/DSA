// Given an array having numbers from 0 to n, but 1 number is missing 
// we have to find that missing number
// Prerequisite:   '^' is used for XOR Bitwise Operation

#include<stdio.h>
int getMissingNumber(int *numbers,int n) // here n represent that array was supposed to contains numbers from 0 to 'n', but 1 number is missing
{
int var,index;
var=0;
for(index=0;index<n;index++)
{
var=(var^index)^numbers[index];
}
return var^index;
}
int main()
{
int x[6]={3,0,1,4,6,2};
printf("Missing number: %d\n",getMissingNumber(x,6));
return 0;
}