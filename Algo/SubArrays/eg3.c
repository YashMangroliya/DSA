// We have given a array and we have to find subarray, sum of the elements of this
//               subarray is equal to given 'requiredSum'.

#include<iostream>
#include<map>
using namespace std;
int main()
{
int x[7]={-2,15,-4,9,-7,4,15};
int requiredSum=2;
map<int,int> numMap;
int accumulatedSum,k,startingIndex;
accumulatedSum=0;
k=0;
while(k<7)
{
accumulatedSum+=x[k];
if(accumulatedSum==requiredSum)
{
printf("Starting index: %d, Ending index: %d",0,k);
break;
}
if(numMap.find(accumulatedSum-requiredSum)!=numMap.end())
{
startingIndex=numMap[accumulatedSum-requiredSum]+1;
printf("Starting index: %d, Ending index: %d",startingIndex,k);
break;
}
else
{
numMap[accumulatedSum]=k;
}
k++;
}
return 0;
}