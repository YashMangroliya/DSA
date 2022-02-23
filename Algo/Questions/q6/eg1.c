// Buy Sell stocks: We have to find maximum profit
// Brute Force

#include<stdio.h>

int getMaximumProfit(int *x,int size)
{
int maxProfit,e,f;
maxProfit=0;
for(e=0;e<size-1;e++)
{
for(f=e+1;f<size;f++) if(x[f]-x[e]>maxProfit) maxProfit=x[f]-x[e];
}
return maxProfit;
}

int main()
{
int x[10]={60,48,79,45,74,32,71,41,10,80};
printf("Maximum Profit: %d\n",getMaximumProfit(x,10));
return 0;
}