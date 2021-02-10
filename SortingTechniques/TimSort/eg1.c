#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
FILE *file=fopen("data.data","wb");
time_t t;
srand((unsigned)time(&t));
int randNum;
for(int i=0;i<5000;i++)
{
randNum=rand();
fwrite((char*) &randNum,sizeof(5),1,file);
}
return 0;
}