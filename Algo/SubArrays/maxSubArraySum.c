#include<stdio.h>
int main()
{
int x[6]={5,-12,6,13,-4};
int e=0,f;
int largest=x[0];
int sum;
while(e<=5)
{
sum=x[e];
if(x[e]>largest) largest=x[e];
f=e+1;
while(f<=5)
{
sum+=x[f];
if(sum>largest) largest=sum;
f++;
}
e++;
}


printf("Max subarray sum is %d",largest);
return 0;
}