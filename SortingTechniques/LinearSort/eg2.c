#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void linearSort(int *x,int cs)
{
int oep,iep,e,f,g;
oep=cs-2;
iep=cs-1;
e=0;
while(e<=oep)
{
f=e+1;
while(f<=iep)
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
}
int main()
{
int *x,y,req,e,f,oep,iep,g;
printf("Enter requirement: ");
scanf("%d",&req);
x=(int*)malloc(sizeof(int)*req);
for(y=0;y<req;y++)
{
printf("Enter number: ");
scanf("%d",&x[y]);
}
linearSort(x,req);
for(y=0;y<req;y++)
{
printf("%d\n",x[y]);
}
free(x);
return 0;
}