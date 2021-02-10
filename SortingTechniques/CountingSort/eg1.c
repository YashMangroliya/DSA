#include<stdio.h>
int main()
{
int x[10],y=0,largest,i;
while(y<10)
{
printf("Enter a number: ");
scanf("%d",&x[y]);
y++;
}

largest=x[0];
y=0;
while(y<10)
{
if(x[y]>largest) largest=x[y];
y++;
}

int arr[largest+1];
for(y=0;y<largest+1;y++) arr[y]=0;
for(y=0;y<10;y++)
{
arr[x[y]]++;
}

for(y=0,i=0;y<largest+1;y++)
{
while(arr[y]>0)
{
x[i]=y;
i++;
arr[y]--;
}
}

for(y=0;y<10;y++) printf("%d\n",x[y]);

return 0;
}