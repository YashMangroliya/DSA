#include<stdio.h>
int main()
{
int x[10],y,size,swapCount,lb,ub,e,f,g,i,forwardFlag,backwardFlag;
size=10;
for(y=0;y<size;y++)
{
printf("Enter a number: ");
scanf("%d",&x[y]);
}
lb=0;
ub=size-1;
swapCount=1;
e=lb;
f=e+1;
forwardFlag=1;
backwardFlag=0;
while(swapCount==1 && lb<ub)
{
swapCount=0;
while(f<=ub && forwardFlag)
{
if(x[e]>x[f])
{
g=x[e];
x[e]=x[f];
x[f]=g;
swapCount=1;
}
e++;
f++;
}


while(e>=lb && backwardFlag)
{
if(x[e]>x[f])
{
g=x[e];
x[e]=x[f];
x[f]=g;
swapCount=1;
}
e--;
f--;
}

if(f>ub)
{
ub--;
f=ub;
e=f-1;
backwardFlag=1;
forwardFlag=0;
}
else if(e<lb)
{
lb++;
e=lb;
f=e+1;
forwardFlag=1;
backwardFlag=0;
}
}

for(i=0;i<size;i++) printf("%d\n",x[i]);
return 0;
}