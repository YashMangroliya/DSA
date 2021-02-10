#include<stdio.h>
#include<stdlib.h>
void merge(int *x,int lb1,int ub1,int lb2,int ub2)
{
printf("%d  %d | %d %d\n",lb1,ub1,lb2,ub2);
int size1=ub1-lb1+1;
int size2=ub2-lb2+1;
int size=size1+size2;
int *tmp;
tmp=(int *)malloc(sizeof(int)*size);
int i1,i2,i3;
i1=lb1;
i2=lb2;
i3=0;
while(i1<=ub1 && i2<=ub2)
{
if(x[i1]<x[i2])
{
tmp[i3]=x[i1];
i1++;
}
else
{
tmp[i3]=x[i2];
i2++;
}
i3++;
}
while(i1<=ub1)
{
tmp[i3]=x[i1];
i3++;
i1++;
}
while(i2<=ub2)
{
tmp[i3]=x[i2];
i3++;
i2++;
}
i3=0;
i1=lb1;
while(i1<=ub1)
{
x[i1]=tmp[i3];
i3++;
i1++;
}
i2=lb2;
while(i2<=ub2)
{
x[i2]=tmp[i3];
i3++;
i2++;
}
if(tmp)free(tmp);
}



void mergeSort(int *x,int lb,int ub)
{
int mid;
if(lb<ub)
{
mid=(ub+lb)/2;
mergeSort(x,lb,mid);
mergeSort(x,mid+1,ub);
merge(x,lb,mid,mid+1,ub);
}
}

int main()
{
int *x,y;
y=0;
x=(int*)malloc(sizeof(int)*10);
while(y<10)
{
printf("Enter a number: ");
scanf("%d",&x[y]);
y++;
}
mergeSort(x,0,9);
for(y=0;y<=9;y++)
{
printf("%d\n",x[y]);
}
return 0;
}