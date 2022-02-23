// Buy Sell stocks: We have to find maximum profit
// Brute Force

#include<stdio.h>

int getMaximumProfit(int *x,int size)
{
int maxProfit,min,i,j;
min=x[0];
maxProfit=0;
for(i=1;i<size;i++)
{
if(x[i]<min)  min=x[i];
else
{
j=x[i]-min;
if(j>maxProfit) maxProfit=j;
}
}
return maxProfit;
}

int main()
{
int x[10]={60,48,79,45,74,32,71,41,10,80};
printf("Maximum Profit: %d\n",getMaximumProfit(x,10));
return 0;
}