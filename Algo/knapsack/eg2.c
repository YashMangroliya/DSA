// Here I will implement Knapsack problem (Bounded) using Iterative method(Dynamic Programming)

#include<stdio.h>
int main()
{
//int weights[5]={5,7,3,10,9};
//int values[5]={2,6,4,5,8};
int weights[6]={1,5,10,15,20,22};
int values[6]={5,2,6,4,5,3};

int size,capacity,value1,value2,i,j;
size=6;
capacity=25;
int store[size+1][capacity+1];
for(i=0;i<size+1;i++) store[i][0]=0;
for(j=0;j<capacity+1;j++) store[0][j]=0;

for(i=1;i<size+1;i++)
{
for(j=1;j<capacity+1;j++)
{
value2=0;
value1=store[i-1][j];
if(j>=weights[i-1]) value2=store[i-1][j-weights[i-1]]+values[i-1];
store[i][j]=(value1>value2)?value1:value2;
}
}

int weightsUsed[size];
int weightsUsedCount=0;
int max=0;
int rowIndex;
int remainingValue;
for(i=0;i<size+1;i++) 
{
if(store[i][capacity]>max)
{
rowIndex=i;
max=store[i][capacity];
}
}
weightsUsed[weightsUsedCount]=weights[rowIndex-1];
weightsUsedCount++;
remainingValue=max-values[rowIndex-1];
rowIndex--;
while(rowIndex>0)
{
if(store[rowIndex-1][capacity]!=store[rowIndex][capacity] && values[rowIndex-1]<=remainingValue) 
{
//is if block me enter karne ki condition: Is cell ki value upar wale cell k barabar nahi hona
//chahiye and ye row jis value ko represent kar rha h vo remaining value se kam hona chahiye.
weightsUsed[weightsUsedCount]=weights[rowIndex-1];
weightsUsedCount++;
remainingValue-=values[rowIndex-1];
}
rowIndex--;
}

printf("Maximum value of items that can be taken in knapsack with capacity %d is %d\n",capacity,max);
printf("Weights of items used: \n");

for(i=0;i<weightsUsedCount;i++) printf("%d ",weightsUsed[i]);
return 0;
}