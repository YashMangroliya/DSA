// In this example, I will create a program to find common subsequences of two arrays.
// (With a better Time Complexity)
// and we will also find length of longest common subsequence

#include<stdio.h>
#include<math.h>
int main()
{
int x[4]={66,67,68,69};
int tmp1[4];
int tmp1i;
int e,j,numX,xEP,lenX,upperBoundX;
int maxSS;

int y[5]={34,66,68,67,69};
int tmp2[5];
int tmp2i;
int numY,yEP,lenY,upperBoundY;

lenX=4;
upperBoundX=lenX-1;
xEP=pow(2,lenX)-1;

lenY=5;
upperBoundY=lenY-1;
yEP=pow(2,lenY)-1;

maxSS=0;
numX=1;
while(numX<=xEP)
{
tmp1i=0;
for(e=upperBoundX;e>=0;e--)
{
j=numX>>e;
if(j&1)
{
tmp1[tmp1i]=x[upperBoundX-e];
tmp1i++;
}
}
// one subsequence of x is in tmp1 array

// logic to search tmp1 in all possible sub sequences of y array starts here

numY=1;
while(numY<=yEP)
{
tmp2i=0;
for(e=upperBoundY;e>=0;e--)
{
j=numY>>e;
if(j&1)
{
tmp2[tmp2i]=y[upperBoundY-e];
tmp2i++;
}
}
// a subsequence of Y array is ready in tmp2, we need to compare it with tmp1
if(tmp1i==tmp2i && tmp1i>maxSS)
{
for(e=0;e<tmp1i;e++)
{
if(tmp1[e]!=tmp2[e]) break;
}
if(e==tmp1i)
{
maxSS=tmp1i;
for(e=0;e<tmp1i;e++) printf("%c",tmp1[e]);
printf("\n");
break;
}
}
numY++;
}
// logic to search tmp1 in all possible sub sequences of y array ends here
numX++;
}
printf("Length of LCS: %d",maxSS);
return 0;
}