// here we will find subsequences from a given array and we will store number and 
//                     index of that number in form of a pair

#include<iostream>
#include<queue>
#include<utility>
using namespace std;
int main()
{
int x[9]={12,3,92,-3,76,93,54,12,78};
int flags[9]={0,0,0,0,0,0,0,0,0};
int e,f,i,prev,noel,maxSS;
queue<queue<pair<int,int>>> list;
maxSS=0;
for(e=0;e<8;e++)
{
if(flags[e]) continue;
prev=e;
noel=0;
queue<pair<int,int>> q;
for(f=e+1;f<9;f++)
{
if(x[f]>x[prev])
{
q.push(pair<int,int>(prev,x[prev]));
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
while(!list.empty()) list.pop();
maxSS=noel;
}
q.push(pair<int,int>(prev,x[prev]));
list.push(q);
}
}

while(!list.empty())
{
queue<pair<int,int>> q=list.front();
list.pop();
while(!q.empty())
{
pair<int,int> p=q.front();
q.pop();
cout<<"("<<p.first<<")"<<p.second<<"  ";
}
cout<<"\n";
}
return 0;
}