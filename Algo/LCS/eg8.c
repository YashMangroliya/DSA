// here we will find length of LCS (USING RECURSIVE ALGORITHM)
// I will be optimising this solution.
#include<stdio.h>

int x[6]={65,66,67,68,80,90};
int y[4]={66,90,68,90};

int lenX=6;
int lenY=4;

int store[4][3];  // I will be using this 2D array to check weather a value is already calculated.


int count=0;
int getLenOfLCS(int e,int f)
{
count++;
int leftSide,rightSide;
if(e==lenX || f==lenY) return 0;
if(store[e][f]!=-1) return store[e][f];
if(x[e]==y[f]) return store[e][f]=1+getLenOfLCS(e+1,f+1);  // value will be assigned first and then value of store[e][f] will be returned
leftSide=(store[e+1][f]!=-1)?store[e+1][f]:getLenOfLCS(e+1,f);
rightSide=(store[e][f+1]!=-1)?store[e][f+1]:getLenOfLCS(e,f+1);
return store[e][f]=(leftSide>rightSide)?leftSide:rightSide;
}

int getLengthOfLCS()
{
int i,j;
for(i=0;i<4;i++)
{
for(j=0;j<3;j++)
{
store[i][j]=-1;
}
}
return getLenOfLCS(0,0);
}

int main()
{
printf("The length of longest common subsequence is: %d\n",getLengthOfLCS());
printf("Number of copies: %d\n",count);
return 0;
}