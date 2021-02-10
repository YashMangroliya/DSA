#include<stdio.h>
#include<stdlib.h>
void insertionSort(int *x,int cs);
void merge(int *x,int lb1,int ub1,int lb2,int ub2);
void mergeSort(int *x,int cs,int size);
int main()
{
FILE *file=fopen("data.data","rb");
int x[5000];
int i,cs;
i=0;
fread((char*)&x,sizeof(5),5000,file);
fclose(file);
i=0;
cs=64;
while(i<5000)
{
if(i+cs>5000) cs=5000-i;
insertionSort(&x[i],cs);
i+=64;
}
mergeSort(&x[0],64,5000);
for(i=0;i<5000;i++)
{
printf("%d\n",x[i]);
}
/*
int x[10];
for(int i=0;i<10;i++)
{
scanf("%d",&x[i]);
}
insertionSort(x,10);
for(int i=0;i<10;i++) printf("%d\n",x[i]);
*/
return 0;
}
void insertionSort(int *x,int cs)
{
int y,z,num;
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

void mergeSort(int *x,int cs,int size)
{
int lb1,ub1,lb2,ub2,lb3,ub3;
lb1=0;
ub1=cs-1;
lb2=ub1+1;
ub2=lb2+cs-1;
while(ub2<size)
{
merge(x,lb1,ub1,lb2,ub2);
ub1+=cs;
lb2=ub1+1;
ub2=lb2+cs-1;
}
if(lb2<size && ub2>=size)
{
ub2=size-1;
merge(x,lb1,ub1,lb2,ub2);
}
}
void merge(int *x,int lb1,int ub1,int lb2,int ub2)
{
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
free(tmp);
}
