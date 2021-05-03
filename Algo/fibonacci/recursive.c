#include<stdio.h>
int count=0;
int fibo(int k)
{
count++;
if(k<=1) return k;
return fibo(k-1)+fibo(k-2);
}

int main()
{
int k;
printf("Enter element number: ");
scanf("%d",&k);
printf("%d\n",fibo(k));
printf("Count: %d\n",count);

return 0;
}