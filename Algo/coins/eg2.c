// Here I will implement the algo to find minimum number of coins required to get the given value
//     I will be using Dynamic programming approach
#include<stdio.h>
#include<limits.h>
int main()
{
int voc[3]={3,5,10};
int value,vocCount,i,j,k,noc;    // voc=varietyOfCoins
value=4;
vocCount=3;
int store[vocCount+1][value+1];
for(j=0;j<value+1;j++) store[0][j]=INT_MAX;
for(i=0;i<vocCount+1;i++) store[i][j]=0;

for(i=1;i<vocCount+1;i++)
{
for(j=1;j<value+1;j++)
{
if(j>=voc[i-1])
{
k=store[i][j-voc[i-1]];
if(k==INT_MAX) store[i][j]=store[i-1][j];
else store[i][j]=(k+1<store[i-1][j])?k+1:store[i-1][j];
}
else
{
store[i][j]=store[i-1][j];
}
}
}

noc=INT_MAX;
for(i=1;i<vocCount+1;i++) if(store[i][value]<noc) noc=store[i][value];

if(noc!=INT_MAX) printf("Number of minimum coins required are: %d\n",noc);
else printf("Not Possible\n");
return 0;
}