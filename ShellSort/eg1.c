#include<stdio.h>
int main()
{
int x[10],y,lb,ub,z,num,size,diff;
y=0;
while(y<10)
{
printf("Enter a number: ");
scanf("%d",&x[y]);
y++;
}

lb=0;
ub=9;
size=ub-lb+1;
diff=size/2;
while(diff>1)
{
y=lb+diff;
while(y<ub)
{
num=x[y];
z=y-diff;
while(z>=0 && x[y]>num)
{
x[z+diff]=x[z];
z-=diff;
}
x[z+diff]=num;
y++;
}
diff/=2;
}

y=0;
while(y<10)
{
printf("%d\n",x[y]);
y++;
}


return 0;
}