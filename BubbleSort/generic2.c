#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void bubbleSort(void * ptr,int cs,int es,int (*p2f)(void* ,void *))
{
int m,e,f,w;
m=cs-2;
int *a,*b,*c;
c=(void*)malloc(es);
while(m>=0)
{
e=0;
f=1;
while(e<=m)
{
a=ptr+(e*es);
b=ptr+(f*es);
w=p2f(a,b);
if(w>0)
{
memcpy(c,(const void*)a,es);
memcpy(a,(const void*)b,es);
memcpy(b,(const void*)c,es);
}
e++;
f++;
}
m--;
}
free(c);
}

int myComparator(void *left,void *right)
{
int *i,*j;
i=(int*)left;
j=(int*)right;
return (*i)-(*j);
}

int main()
{
int req,y;
int *x;
printf("Enter requirement: ");
x=(int*)malloc(sizeof(int)*req);
scanf("%d",&req);
for(y=0;y<req;y++)
{
printf("Enter number: ");
scanf("%d",&x[y]);
}
bubbleSort(x,req,sizeof(int),myComparator);
for(y=0;y<req;y++)
{
printf("%d\n",x[y]);
}
free(x);
return 0;
}