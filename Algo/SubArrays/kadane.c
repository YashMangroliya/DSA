#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
int main()
{
int x[6]={10,-2,7,-6,11,-9};
int lmax,gmax,si,ei; // si=starting index, ei=ending index
lmax=x[0];
gmax=x[0];
int i=1;
while(i<=5)
{
if(x[i]>(lmax+x[i]))
{
lmax=x[i];
si=i;
}
else
{
lmax=lmax+x[i];
}
if(lmax>gmax)
{
gmax=lmax;
ei=i;
}
i++;
}



if(gmax<0) gmax=0; 
printf("Maximum sum of subarray: %d\n",gmax);
printf("Starting index: %d, Ending index: %d",si,ei);
return 0;
}