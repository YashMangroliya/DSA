// We have to find number of ways to climb n stairs
// Given that we can climb 1 or 2 stairs at a time

#include<stdio.h>
int getNumberOfWaysToClimbStairs(int stairs)
{
int e,f,g,k;
if(stairs<=2) return stairs;
e=1;
f=2;
k=3;
while(k<=stairs)
{
g=e+f;
e=f;
f=g;
k++;
}
return g;
}

int main()
{
printf("%d\n",getNumberOfWaysToClimbStairs(5));
return 0;
}