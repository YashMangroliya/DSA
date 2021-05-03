#include<stdio.h>

int* _matrixMultiplication(int *firstMatrix,int frs,int fre,int fcs,int fce,int *secondMatrix,int srs,int sre,int scs,int sce,int* resultMatrix,int factor)
{
int size=fre-frs+1;
if(size>2)
{

for(e=0;e<4;e++)
{
for(f=0;f<4;f++)
{
for(g=0;g<4;g++)
{
_matricMultiplication(firstMatrix,frs,
num=num+A[e][g]*B[g][f];
}
}
}



} //if
else
{

for(e=frs;e<fre;e++)
{
for(f=srs;f<sre;f++)
{
num=0;
for(g=0;g<2;g++)
{
num=num+A[e][g]*B[g][f];
}
C[e][f]=num;
}
}



//resultMatrix[frs+e][fcs+f]=firstMatrix[frs+
}
}

}






}

int* matrixMultiplication(int *firstMatrix,int rowsInFirstMatrix,int columnsInFirstMatrix,int *secondMatrix,int rowsInSecondMatrix,int columnsInSecondMatrix)
{
int c=(int*)malloc(sizeof(int)*rowsInFirstMatrix*columnsInSecondMatrix);
return _matrixMultiplication(firstMatrix,rowsInFirstMatrix,columnsInFirstMatrix,secondMatrix,rowsInSecondMatrix,columnsInSecondMatrix,c);
}


int main()
{
int A[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
int B[4][4]={{10,20,30,40},{50,60,70,80},{90,100,110,120},{130,140,150,160}};
int e,f,g,num;
int c[4][4];
matrixMutiplication(A,4,4,B,4,4);



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