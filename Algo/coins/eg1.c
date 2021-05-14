// In this example, we will implement the Brute Force method to find number of Coins
//        required to get required number.

#include<stdio.h>
#include<limits.h> // for Max factor of a datatype
int voc[3]={5,10,12};    // voc=Variation of coins
int vocCount=3;
int getMinCoins(int value)
{
int noc,k,i;
if(value==0) return 0;
noc=INT_MAX-1;
for(i=0;i<vocCount;i++)
{
if(voc[i]<=value)
{
k=getMinCoins(value-voc[i]);
if(k+1<noc) noc=k+1;
}
}
return noc;
}
int main()
{
int noc=getMinCoins(15);
if(noc==2147483646) printf("Not Possible\n");
else printf("NOC: %d\n",noc);
return 0;
}