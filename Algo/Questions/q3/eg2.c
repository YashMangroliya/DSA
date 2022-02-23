// Given an array of numbers containing numbers from 1 to n, but there are some numbers
// from 1 to n which are not in the given array. We have to find all those numbers.

#include<stdio.h>
#include<stdlib.h>

void getMissingElements(int *numbers,int size)
{
int e=0;
for(e=0;e<size;e++)
{
if(numbers[e]>0)
{
if(numbers[numbers[e]-1]>0) numbers[numbers[e]-1]= (-1)*numbers[numbers[e]-1];
}
else
{
if(numbers[-1*numbers[e]-1]>0) numbers[-1*numbers[e]-1]= (-1)*numbers[-1*numbers[e]-1];
}
}
}

int main()
{
int x[9]={2,3,3,3,4,2,3,3,3};
getMissingElements(x,9);
printf("Missing numbers are: ");
for(int e=0;e<5;e++)
{
if(x[e]>0) printf("%d ",e+1);
}
return 0;
}