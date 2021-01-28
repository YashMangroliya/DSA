#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void selectionSort(void* ptr,int cs,int es,int (*p2f)(void*,void*));
int myComparator(void* left,void* right)
{
int *a,*b;
a=(int*)left;
b=(int*)right;
return *a-*b;
}
int main()
{
int *x,req,y;
printf("Enter requirement: ");
scanf("%d",&req);
y=0;
x=(int*)malloc(sizeof(int)*req);
while(y<req)
{
printf("Enter a number: ");
scanf("%d",&x[y]);
y++;
}
selectionSort(x,req,sizeof(int),myComparator);
for(y=0;y<req;y++)
{
printf("%d\n",x[y]);
}
free(x);
return 0;
}
void selectionSort(void* ptr,int cs,int es,int (*p2f)(void*,void*))
{
int oep,iep,e,f,si,w;
void *a,*b,*c;
oep=cs-2;
iep=cs-1;
e=0;
c=(void*)malloc(es);
while(e<=oep)
{
si=e;
f=e+1;
while(f<=iep)
{
a=ptr+(f*es);
b=ptr+(si*es);
w=p2f(a,b);
if(w<0)
{
si=f;
}
f++;
}
a=ptr+(e*es);
b=ptr+(si*es);
memcpy(c,(const void*)a,es);
memcpy(a,(const void*)b,es);
memcpy(b,(const void*)c,es);
e++;
}
free(c);
}
