#include<stdio.h>
int kthSmallest(int *x,int k,int size)
{
int i,ci,ri,g,swapCount,lci,rci,swi;

// converting x array to Min Heap
ci=1;
while(ci<size)
{
while(ci>0)
{
ri=(ci-1)/2;
if(x[ri]>x[ci])
{
g=x[ci];
x[ci]=x[ri];
x[ri]=g;
ci=ri;
}
else break;
}
ci++;
}


// adjusting Mean Heap

i=0;
int ub=size-1;
while(i<(k-1))
{
x[0]=x[ub];
ub--;

ri=0;
while(ri<ub)
{
lci=ri*2+1;
if(lci>ub) break;
rci=lci+1;
if(rci>ub) swi=lci;
else
{
if( x[lci]<x[rci]) swi=lci;
else swi=rci;
}
if(x[swi]<x[ri])
{
g=x[swi];
x[swi]=x[ri];
x[ri]=g;
ri=swi;
}
else break;
}
i++;
}
return x[0];
}


int main()
{
int x[10]={25,48,624,10,32,4,9,65,3,23};
int num=kthSmallest(x,5,10);
printf("%dth smallest is: %d",5,num);
return 0;
}