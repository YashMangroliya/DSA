// In this example I will be implementing logic to find length of LCS using GRID/MATRIX technique
// and will traverse back to find the subsequence

// In this example I will be implementing logic to find length of LCS using GRID/MATRIX technique
#include<stdio.h>
#include<limits.h>
int main()
{
int x[6]={64,66,90,80,8,3};
int y[5]={66,64,90,8,40};
int lenX=6;
int lenY=5;

int matrix[lenX+1][lenY+1];
int i,j,indexX,indexY;
for(j=0;j<=lenY;j++) matrix[0][j]=0;
for(i=0;i<=lenX;i++) matrix[i][0]=0;
int maxSS=INT_MIN;
for(i=1;i<=lenX;i++)
{
for(j=1;j<lenY;j++)
{
if(x[i-1]==y[j-1])
{
matrix[i][j]=matrix[i-1][j-1]+1;
if(matrix[i][j]>maxSS)
{
maxSS=matrix[i][j];
indexX=i;
indexY=j;
}
}
else
{
matrix[i][j]=(matrix[i-1][j]>matrix[i][j-1])?matrix[i-1][j]:matrix[i][j-1];
}
}
}

int ans[maxSS];
int index=maxSS-1;
while(indexX>0 || indexY>0)
{
if(matrix[indexX][indexY]==matrix[indexX-1][indexY]) indexX--;
else if(matrix[indexX][indexY]==matrix[indexX][indexY-1]) indexY--;
else if(matrix[indexX][indexY]==matrix[indexX-1][indexY-1]+1)
{
ans[index]=x[indexX-1];
index--;
indexX--;
indexY--;
}
}

printf("Length of LCS is: %d\n",maxSS);
i=0;
printf("Longest Common subsequence is: ");
while(i<maxSS)
{
printf("%d ",ans[i]);
i++;
}
return 0;
}
