#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void linearSort(void *ptr,int cs,int es,int (*p2f)(void*,void*));
int myComparator(void*,void*);
int main()
{
int *x,req,y;
printf("Enter your requirement: ");
scanf("%d",&req);
x=(int*)malloc(sizeof(int)*req);
for(y=0;y<req;y++)
{
printf("Enter number: ");
scanf("%d",&x[y]);
}
linearSort(x,req,sizeof(int),myComparator);
for(y=0;y<req;y++)
{
printf("%d\n",x[y]);
}
return 0;
}

void linearSort(void *ptr,int cs,int es,int (*p2f)(void*,void*))
{
int oep,iep,y,f,e,w;
void *a,*b,*c;
e=0;
oep=cs-2;
iep=cs-1;
c=malloc(sizeof(es));
while(e<=oep)
{
f=e+1;
while(f<=iep)
{
a=(void*)(ptr+(f*es));
b=(void*)(ptr+(e*es));
w=p2f(a,b);
if(w<0)
{
memcpy(c,a,es);
memcpy(a,b,es);
memcpy(b,c,es);
}
f++;
}
e++;
}
}

int myComparator(void* left,void* right)
{
int *a,*b;
a=(int*)left;
b=(int*)right;
return *a-*b;
}