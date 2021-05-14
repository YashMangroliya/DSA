// Here I will implement the algo to find minimum number of coins required to get the given value
// and will try to know which coins were used and their count also
//     I will be using Dynamic programming approach
#include<iostream>
#include<limits.h>
#include<map>
//#include<bits/stdc++.h>
using namespace std;
int main()
{
int voc[3]={2,5,10};
int value,vocCount,i,j,k,noc;    // voc=varietyOfCoins
value=10;
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

// finding minimum value in valueTH column
noc=INT_MAX;
int rowIndex;
for(i=1;i<vocCount+1;i++)
{
if(store[i][value]<noc)
{
rowIndex=i;
noc=store[i][value];
}
}

// Back-Traking code starts here
map<int,int> m;     // map<which coin, How many times used>
if(noc!=INT_MAX)
{
i=rowIndex;
j=value;
while(store[i][j])
{
if(store[i][j]==store[i-1][j]) // Upar wale cell se copy kiya gya hai kya
{
i--;
continue;
}
if(m.find(voc[i-1])!=m.end()) m[voc[i-1]]++;
else m[voc[i-1]]=1;
j-=voc[i-1];
}
}

// Back-Traking code ends here





if(noc==INT_MAX) printf("Not Possible\n");
else 
{
printf("Number of minimum coins required to get %d are: %d\n",value,noc);
printf("Coins used are: \n");
for(map<int,int>::iterator itr=m.begin();itr!=m.end();itr++) printf("%d coins of %d\n",itr->second,itr->first);
}
return 0;
}