#include<stdio.h>
int main()
{
int A[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
int B[4][4]={{10,20,30,40},{50,60,70,80},{90,100,110,120},{130,140,150,160}};
int e,f,g,num;
int c[4][4];
for(e=0;e<4;e++)
{
for(f=0;f<4;f++)
{
num=0;
for(g=0;g<4;g++)
{
num=num+A[e][g]*B[g][f];
}
c[e][f]=num;
}
}

printf("      ");
for(e=0;e<4;e++)
{
printf("%5d ",e);
}
printf("\n");
for(e=0;e<4;e++)
{
printf("%5d ",e);
for(f=0;f<4;f++)
{
printf("%5d ",c[e][f]);
}
printf("\n");
}

return 0;
}