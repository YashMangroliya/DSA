// In this program, we will solve overlap problem my mentaining a global array

#include<stdio.h>
#include<stdlib.h>
int *arr;
int count=0;
int fibo(int k)
{
count++;
if(arr[k]==0)
{
if(k<=1) arr[k]=k;
else
{
arr[k]=fibo(k-1)+fibo(k-2);
}
}
return arr[k];
}

int main()
{
int k;
printf("Enter element number: ");
scanf("%d",&k);
arr=(int*)calloc((k+1),sizeof(int));
int i=0;
/*while(i<=k)
{
arr[i]=0	;
i++;
}*/
printf("%d\n",fibo(k));
printf("Count: %d\n",count);

return 0;
}