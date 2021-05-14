#include<stdio.h>
int main()
{
int x[10]={0,0,1,1,0,1,1,0,0,0};
int e,f,zeroCount=0;
e=0;
f=9;
while(e<=f)
{
if(x[e]==0)
{
zeroCount++;
}
e++;
}
e=0;
while(e<zeroCount)
{
x[e]=0;
e++;
}
while(e<=f)
{
x[e]=1;
e++;
}

for(e=0;e<=9;e++)
{
printf("%d",x[e]);
}


return 0;
}