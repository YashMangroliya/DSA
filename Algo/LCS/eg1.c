#include<stdio.h>
int main()
{
int x[9]={12,3,92,-3,76,93,54,12,78};
int flags[9]={0,0,0,0,0,0,0,0,0};
int e,f,i,prev;
for(e=0;e<8;e++)
{
if(flags[e]) continue;
prev=e;
for(f=e+1;f<9;f++)
{
if(x[f]>x[prev])
{
printf("%d,",x[prev]);
flags[f]=1;
prev=f;
}
}
if(prev>e)
{
printf("%d",x[prev]);
printf("\n");
}
}


return 0;
}