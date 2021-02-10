#include<stdio.h>
void stoogSort(int *x,int lb,int ub);
int main()
{
int x[10],y,size;
size=10;
for(y=0;y<size;y++)
{
printf("Enter a number: ");
scanf("%d",&x[y]);
}
stoogSort(&x[0],0,size-1);
for(y=0;y<size;y++)
{
printf("%d\n",x[y]);
}
return 0;
}

void stoogSort(int *x,int lb,int ub)
{
int g,size,subSize;
if(x[lb]>x[ub])
{
g=x[lb];
x[lb]=x[ub];
x[ub]=g;
}
size=ub-lb+1;
if(size>2)
{
subSize=size-(size/3);
stoogSort(x,lb,lb+subSize-1);
stoogSort(x,ub-subSize+1,ub);
stoogSort(x,lb,lb+subSize-1);
}
}