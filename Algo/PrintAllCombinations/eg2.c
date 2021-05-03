#include<stdio.h>
int main()
{
int a;
printf("Enter number: ");
scanf("%d",&a);

for(int i=0;i<=4;i++)
{
printf("%d\n",(a>>i) & 1);
}

return 0;
}