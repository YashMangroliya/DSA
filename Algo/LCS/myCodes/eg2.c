// In this example, we will find increasing sequences(can be non-continuous) 
//       from a given array.

#include<iostream>
#include<bits/stdc++.h>
#include<list>
using namespace std;
int main()
{
//int x[10]={12,3,92,-3,76,54,12,93,78};
int x[10]={14,9,18,24,11,28,20,22};
list<list<int>*> listOfList;
list<int> *l;
int sp=0,i=0,num,size;
bool found=false;
int j=0;
while(sp<9)
{
i=sp;
num=x[i];
found=false;
j=0;
for(list<int> *l1:listOfList)
{
if(j==0)
{
j++;
continue;
}
if(find(l1->begin(),l1->end(),num)!=l1->end())
{
found=true;
break;
}
}

i++;
l=new list<int>;
if(!found)
{
while(i<10)
{
if(x[i]>num)
{
//printf("%d,",num);
l->push_back(num);
num=x[i];
}
i++;
}
//printf("%d",num);
l->push_back(num);
if(l->size()>1) listOfList.push_back(l);
}
//printf("\n");
sp++;
}

for(list<int>* l:listOfList)
{
size=l->size();
i=1;
for(int n: *l)
{
printf("%d",n);
if(i!=size) printf(",");
i++;
}
printf("\n");
}
return 0;
}