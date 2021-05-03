// Here we are finding longest common subsequences between two arrays
#include<stdio.h>
#include<stdlib.h>
#include<list>
using namespace std;
bool areListsSame(list<int> *lX,list<int> * lY);
int main()
{
int x[10]={12,3,92,-3,76,93,54,12,78};
int y[10]={13,12,3,-17,92,87,93,54,78,15};
//int y[10]={15,78,35,31,459,9,84,56,33,8};
int sp=0,i=0,num,size,maxSize=0;
int *flags=(int*)calloc(11,sizeof(int));
list<list<int>*> listOfListX;
list<list<int>*> listOfListY;
list<int> *l;
list<list<int>*> commonSubsequenceList;
// finding subsequences of x array
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
l->push_back(num);
size++;
num=x[i];
flags[i]=1;
}
i++;
}
if(num!=x[sp]) 
{
l->push_back(num);
size++;
}
if(size>maxSize) maxSize=size;
listOfListX.push_back(l);
}
sp++;
}

// finding subsequences of y array
for(i=0;i<11;i++) flags[i]=0;
sp=0;
i=0;
maxSize=0;
while(sp<9)
{
num=y[sp];
i=sp+1;
if(flags[sp]==0)
{
l=new list<int>;
size=0;
while(i<10)
{
if(y[i]>num)
{
l->push_back(num);
size++;
num=y[i];
flags[i]=1;
}
i++;
}
if(num!=y[sp]) 
{
l->push_back(num);
size++;
}
if(size>maxSize) maxSize=size;
listOfListY.push_back(l);
}
sp++;
}








size=0;
maxSize=0;
for(list<int> *lX : listOfListX)
{
for(list<int> *lY: listOfListY)
{
if(areListsSame(lX,lY))
{
size=lX->size();
if(size>maxSize) maxSize=size;
commonSubsequenceList.push_back(lX);
}
}
}


//printf("%d",commonSubsequenceList.size());
if(commonSubsequenceList.size()==0)
{
printf("No common subsequence found\n");
return 0;
}
for(list<int> *l: commonSubsequenceList)
{
size=l->size();
if(size!=maxSize) continue;
i=1;
for(int num: *l)
{
printf("%d",num);
if(i!=size) printf(",");
i++;
}
printf("\n");
}
return 0;
}

bool areListsSame(list<int> *lX,list<int> * lY)
{
int sizeX=lX->size();
int sizeY=lY->size();
if(sizeX!=sizeY) return false;
list<int>::iterator itrX=lX->begin();
list<int>::iterator itrY=lY->begin();
for(;itrX!=lX->end();itrX++,itrY++)
{
if(*itrX!=*itrY) return false;
}
return true;
}