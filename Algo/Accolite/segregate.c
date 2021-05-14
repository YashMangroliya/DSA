#include<stdio.h>
int main()
{
int x[10]={0,0,1,1,0,1,1,0,0,0};
int left,right,e,g;
left=0;
right=9;
while(left<right)
{
while(left<right && x[left]==0)
{
left++;
}
while(left<right && x[right]==1)
{
right--;
}
if(left<right)
{
g=x[left];
x[left]=x[right];
x[right]=g;
left++;
right--;
}
}
for(e=0;e<=9;e++)
{
printf("%d",x[e]);
}
return 0;
}