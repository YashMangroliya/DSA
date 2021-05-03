#include<stdio.h>
int main()
{
int k,x,y,z,j;
printf("Enter element number: ");
scanf("%d",&k);
j=1;
x=0;
y=1;
while(j<k)
{
z=x+y;
x=y;
y=z;
j++;
}
printf("%d\n",y);
return 0;
}