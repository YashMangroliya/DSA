// Here, we are finding sub sequences of an array
#include<stdio.h>
#include<stdlib.h>
#include<list>
using namespace std;
int main()
{
int x[10]={12,3,92,-3,76,93,54,12,78};
int sp=0,i=0,num,size,maxSize=0;
int *flags=(int*)calloc(10,sizeof(int));
list<list<int>*> listOfList;
list<int> *l;
while(sp<9)
{
num=x[sp];
i=sp+1;
if(flags[sp]==0)
{
l=new list<int>;
size=0;
while(i<10)
{
if(x[i]>num)
{
//printf("%d,",num);
l->push_back(num);
size++;
num=x[i];
flags[i]=1;
}
i++;
}
if(num!=x[sp]) 
{
//printf("%d",num);
l->push_back(num);
size++;
//printf("\n");
}
if(size>maxSize) maxSize=size;
listOfList.push_back(l);
}
sp++;
}

printf("%d\n",listOfList.size());
for(list<int> *l:listOfList)
{
if(l->size()!=maxSize) continue;
for(int num: *l) printf("%d,",num);
printf("\n");
}

return 0;
}