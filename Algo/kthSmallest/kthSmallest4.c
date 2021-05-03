#include<stdio.h>
int kthSmallest(int *x,int k,int size)
{
int ci,ri,lci,rci,swi,g,ub,i;
ub=1;
while(ub<k)
{
ci=ub;
while(ci>0)
{
ri=(ci-1)/2;
if(x[ri]<x[ci])
{
g=x[ci];
x[ci]=x[ri];
x[ri]=g;
ci=ri;
}
else break;
}
ub++;
}

i=k;
while(i<size)
{
if(x[i]<x[0])
{
g=x[i];
x[i]=x[0];
x[0]=g;

ri=0;
while(ri<k)
{
lci=ri*2+1;
if(lci>=k) break;
rci=lci+1;
if(rci>=k) swi=lci;
else
{
if(x[lci]>x[rci]) swi=lci;
else swi=rci;
}
if(x[swi]>x[ri])
{
g=x[ri];
x[ri]=x[swi];
x[swi]=g;
ri=swi;
}
else break;
}
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