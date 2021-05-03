// here we will find sub-sequences from a given array and we will store  
// the indexes of first and last number of that sub-sequence in form of a pair

#include<iostream>
#include<forward_list>
#include<utility>
using namespace std;
int main()
{
int x[9]={12,3,92,-3,76,93,54,12,78};
int flags[9]={0,0,0,0,0,0,0,0,0};
int e,f,i,prev,noel,maxSS;
forward_list<pair<int,int>> list;
maxSS=0;
for(e=0;e<8;e++)
{
if(flags[e]) continue;
prev=e;
noel=0;
for(f=e+1;f<9;f++)
{
if(x[f]>x[prev])
{
flags[f]=1;
prev=f;
noel++;
}
}
if(prev>e)
{
noel++;
if(noel<maxSS) continue;
if(noel>maxSS)
{
list.clear();
maxSS=noel;
}
list.push_front(pair<int,int>(e,prev));
}
}

for(pair<int,int> p:list)
{
prev=p.first;
for(f=prev+1;f<=p.second;f++)
{
if(x[f]>x[prev])
{
cout<<x[prev]<<",";
prev=f;
}
}
cout<<x[prev]<<endl;
}
return 0;
}