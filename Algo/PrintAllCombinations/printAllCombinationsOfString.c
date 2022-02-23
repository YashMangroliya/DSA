// In this exmaple we have given an string and we will find all possible combinations
// of this string.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int count=0;
void _printAllCombinationsOfString(char *str,int si,int ei)
{
if(si==ei)
{
count++;
for(int i=0;i<=ei;i++) printf("%c",str[i]);
printf("\n");
return;
}
char c;
int k;
int found;
for(int j=si;j<=ei;j++)
{
found=0;
for(k=si;k<j;k++)
{
if(str[k]==str[j])
{
found=1;
break;
}
}
if(found) continue;
c=str[si];
str[si]=str[j];
str[j]=c;
_printAllCombinationsOfString(str,si+1,ei);
c=str[si];
str[si]=str[j];
str[j]=c;
}
}
void printAllCombinationsOfString(char *str,int size)
{
_printAllCombinationsOfString(str,0,size-1);
}
int main()
{
char str[7]="HISTORY";
printAllCombinationsOfString(str,7);
printf("Count: %d\n",count);
return 0;
}
