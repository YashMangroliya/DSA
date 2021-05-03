#include<stdio.h>
#include<stdlib.h>
int main()
{
int x[10]={12,3,92,-3,76,93,54,12,78};
int sp=0,i=0,num;
int *flags=(int*)calloc(10,sizeof(int));
while(sp<9)
{
num=x[sp];
i=sp+1;
if(flags[sp]==0)
{
while(i<10)
{
if(x[i]>num)
{
printf("%d,",num);
num=x[i];
flags[i]=1;
}
i++;
}
if(num!=x[sp]) 
{
printf("%d",num);
printf("\n");
}
}
sp++;
}


return 0;
}