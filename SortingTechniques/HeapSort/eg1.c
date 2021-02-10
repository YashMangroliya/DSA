#include<stdio.h>
int main()
{
int x[10],y,e,ci,ri,lci,rci,g,swi;
y=0;
while(y<10)
{
printf("Enter a number: ");
scanf("%d",&x[y]);
y++;
}

printf("point 1\n");
//code to convert array into Heap

e=1;
while(e<=9)
{
printf("point 2\n");
ci=e;
while(ci>0)
{
printf("point 3\n");
ri=(ci-1)/2;
if(x[ci]>x[ri])
{
g=x[ci];
x[ci]=x[ri];
x[ri]=g;
ci=ri;
}
else break;
}
e++;
}

// Heap Sort code

e=9;
while(e>0)
{
printf("point 4\n");
g=x[e];
x[e]=x[0];
x[0]=g;
e--;

// code to adjust Heap

ri=0;
while(ri<e)
{
printf("point 5\n");
lci=(ri*2)+1;
if(lci>e) break;
rci=lci+1;
if(rci>e) swi=lci;
else
{
if(x[lci]>x[rci]) swi=lci;
else swi=rci;
}
if(x[swi]>x[ri])
{
g=x[swi];
x[swi]=x[ri];
x[ri]=g;
ri=swi;
}
else break;
}
}
for(y=0;y<10;y++)
{
printf("%d\n",x[y]);
}
return 0;
}