// here we will find subsequences from a given array and we will print those sub-sequences 

#include<stdio.h>
int main()
{
int x[9]={12,3,92,-3,76,93,54,12,78};
int flags[9]={0,0,0,0,0,0,0,0,0};
int e,f,i,prev,noel;
for(e=0;e<8;e++)
{
if(flags[e]) continue;
prev=e;
noel=0;
for(f=e+1;f<9;f++)
{
if(x[f]>x[prev])
{
printf("%d,",x[prev]);
flags[f]=1;
prev=f;
noel++;
}
}
if(prev>e)
{
printf("%d",x[prev]);
noel++;
printf("\n");
printf("The above %d elements are from %d to %d\n\n",noel,e,prev);
}
}


return 0;
}