#include<stdio.h>
int main()
{
int arr[]={1,2,3,4};
int size,i,j,endNum;
size=4;
endNum=15;
for(i=1;i<=endNum;i++)
{
for(j=0;j<size;j++)
{
if((i>>j) & 1) printf("%d",arr[j]);
}
printf("\n");
}

return 0;
}