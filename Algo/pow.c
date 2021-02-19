#include<stdio.h>
int m[32]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int count=0;
int poww(int b,int p)
{
count++;
if(p==1) return b;
if(m[p]!=0) return m[p];
m[p]=(p%2==0)?poww(b,p/2)*poww(b,p/2):poww(b,p/2)*poww(b,p/2)*b;
return m[p];
}

int power(int b,int c)
{
if(c==0) return 1;
return poww(b,c);
}
int main()
{
int b,p,i;
printf("Enter base: ");
scanf("%d",&b);
printf("Enter power: ");
scanf("%d",&p);
printf("%d\n",power(b,p));
printf("Count: %d\n",count);
return 0;
}