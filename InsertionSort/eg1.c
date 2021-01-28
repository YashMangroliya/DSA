#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void insertionSort(int *x,int cs)
{
int num,y,z;
y=1;
while(y<cs)
{
num=x[y];
z=y-1;
while(z>=0 && x[z]>num)
{
x[z+1]=x[z];
z--;
}
x[z+1]=num;
y++;
}
}
int main()
{
int *x,req,y;
printf("Enter your requirement: ");
scanf("%d",&req);
x=(int*)malloc(sizeof(int)*req);
for(y=0;y<req;y++)
{
printf("Enter a number: ");
scanf("%d",&x[y]);
}
insertionSort(x,req);
for(y=0;y<req;y++)
{
printf("%d\n",x[y]);
}
return 0;
}