// Given an array of numbers containing numbers from 1 to n, but there are some numbers
// from 1 to n which are not in the given array. We have to find all those numbers.

#include<stdio.h>
#include<stdlib.h>
struct MissingElements
{
int *elements;
int size;
};

struct MissingElements  getMissingElements(int *numbers,int size,int n)
{
int e,f;
struct MissingElements missingElements;
missingElements.elements=(int*)calloc(sizeof(int),n);
for(e=0;e<size;e++)
{
missingElements.elements[numbers[e]-1]++;
}
for(e=0,f=0;e<n;e++)
{
if(missingElements.elements[e]==0)
{
missingElements.elements[f]=e+1;
f++;
}
}
missingElements.size=f;
return missingElements;
}

int main()
{
int x[9]={3,3,2,4,3,3,3,2,4};
struct MissingElements missingElements;
missingElements=getMissingElements(x,9,5);
printf("Missing numbers are: ");
for(int e=0;e<missingElements.size;e++)
{
printf("%d ",missingElements.elements[e]);
}
return 0;
}