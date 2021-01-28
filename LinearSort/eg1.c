#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
int x[10],y,req,e,f,oep,iep,g;
//printf("Enter requirement: ");
//scanf("%d",&req);
req=10;
for(y=0;y<req;y++)
{
printf("Enter number: ");
scanf("%d",&x[y]);
}
oep=req-2;
iep=req-1;
e=0;
while(e<=oep)
{
f=e+1;
while(f<=req-1)
{
if(x[f]<x[e])
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
f++;
}
e++;
}
for(y=0;y<req;y++)
{
printf("%d\n",x[y]);
}
return 0;
}