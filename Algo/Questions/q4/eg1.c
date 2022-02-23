// Given an array of int, all the numbers in the array occurs twice, but there is a number
// which occurs only once. We have to find that number.
// Prerequisite:  
//            A^A=0 --> 0^B=B  ==>   A^A^B=B  and A^B^A=B                         '^' means XOR

#include<stdio.h>
int getSingleNum(int *numbers,int size)
{
int e,num;
for(num=0,e=0;e<size;e++) num=num^numbers[e];
return num;
}
int main()
{
int x[5]={1,3,3,2,1};
printf("Single number is: %d\n",getSingleNum(x,5));
return 0;
}