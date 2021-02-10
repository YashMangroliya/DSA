#include<stdio.h>
#include<stdlib.h>
void quickSort(int *x,int lb,int ub);
int findPartitionPoint(int *x,int lb,int ub);
int main()
{
FILE *file=fopen("data.data","rb");
fseek(file,0,2);
int numberOfRecords=ftell(file)/4;
fseek(file,0,0);
int numberOfRecordsInSubFile=numberOfRecords/10;
printf("%d\n",numberOfRecords);
char *fileName[10];
int i=0,j=0;
int num;
int *arr;
FILE *f;
int pos=0;
for(int index=0;index<10;index++)
{
arr=(int*)malloc(sizeof(int)*(numberOfRecordsInSubFile));
fileName[index]=(char*)malloc(sizeof(char)*10);
sprintf(fileName[index],"data%d.data",index);
fread((char*)&arr[0],sizeof(5),numberOfRecordsInSubFile,file);

quickSort(arr,0,numberOfRecordsInSubFile-1);

f=fopen(fileName[index],"wb");
fwrite((char*)&arr[0],sizeof(5),numberOfRecordsInSubFile,f);
fclose(f);
free(arr);
}
fclose(file);
// Till here, we have created 10 sorted subfiles of "data.data" file
// now we will perform merge sort on these 10 file to create a sorted file "sortedData.data"


int flagArray[10];
int valueArray[10];
int closedFilesCount=0;
int smallest=0;
printf("-------------------------\n");
FILE *files[10];

for(i=0;i<10;i++)
{
files[i]=fopen(fileName[i],"rb");
fread((char*)&valueArray[i],sizeof(5),1,files[i]);
flagArray[i]=1;
}

FILE * sortedFile=fopen("sortedData.data","wb");

while(closedFilesCount<10)
{
for(i=0;i<10;i++)
{
if(flagArray[i])
{
smallest=i;
break;
}
}
for(;i<10;i++)
{
if(flagArray[smallest] && valueArray[i]<valueArray[smallest]) smallest=i;
}

fwrite((char*)&valueArray[smallest],sizeof(5),1,sortedFile);
if(!feof(files[smallest]))
{
fread((char*)&valueArray[smallest],sizeof(5),1,files[smallest]);
}
else
{
fclose(files[smallest]);
flagArray[smallest]=0;
closedFilesCount++;
}
}//while
fclose(sortedFile);
return 0;
}






int findPartitionPoint(int *x,int lb,int ub)
{
int e,f,g;
e=lb;
f=ub;
while(e<f)
{
while(e<ub && x[e]<=x[lb]) e++;
while(x[f]>x[lb]) f--;
if(e<f)
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
else
{
g=x[lb];
x[lb]=x[f];
x[f]=g;
}
}
return f;
}

void quickSort(int *x,int lb,int ub)
{
if(lb>=ub) return;
int pp=findPartitionPoint(x,lb,ub);
quickSort(x,lb,pp-1);
quickSort(x,pp+1,ub);
}
