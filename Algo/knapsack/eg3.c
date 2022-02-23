// Here we will implement knapsack problem(UNBounded) by applyting brute force
// (ek copy apna kaam karke baki ka kaam next copy karne k liye de degi)
// *UNBounded- 1 item keval 1 bar hi aa sakta hai


#include<stdio.h>
#include<limits.h>
int _getKnapsackFillValue(int* weights,int* values,int size,int capacity,int index)
{
if(capacity<=0 || index>=size) return 0;
int value1,value2,value3;
value1=0;
value3=0;
if(weights[index]<=capacity) value1=values[index]+_getKnapsackFillValue(weights,values,size,capacity-weights[index],index+1);
value2=_getKnapsackFillValue(weights,values,size,capacity,index+1);
if(weights[index]<=capacity) value3=values[index]+_getKnapsackFillValue(weights,values,size,capacity-weights[index],index);
if(value1>value2 && value1>value3) return value1;
if(value2>value1 && value2>value3) return value2;
if(value3>value1 && value3>value2) return value3;
}
int getKnapsackFillValue(int* weights,int* values,int size,int capacity)
{
return _getKnapsackFillValue(weights,values,size,capacity,0);
}


int main()
{
//int weights[6]={1,5,10,15,20,22};
//int values[6]={5,2,6,4,5,3};
int weights[5]={5,7,3,10,9};
int values[5]={2,6,4,5,8};

int size,capacity;
size=5;
capacity=17;
printf("Max value that can be taken away in the knapsack with capacity %d is : %d\n",capacity,getKnapsackFillValue(weights,values,size,capacity));
return 0;
}