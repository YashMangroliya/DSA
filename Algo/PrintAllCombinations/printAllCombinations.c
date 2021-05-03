// In this exmaple we have given an array of n characters and we will find all possible  
// k digit combinations
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int count=0;
void _printAllCombinations(char *seed,char *charSet,int setSize,int maxLength)
{
if(maxLength==0)
{
count++;
printf("%s\n",seed);
return;
}
int seedLength=strlen(seed);
char *str=(char*)malloc(sizeof(char)*seedLength+2);
strcpy(str,seed);
for(int i=0;i<setSize;i++)
{
str[seedLength]=charSet[i];
str[seedLength+1]='\0';
_printAllCombinations(str,charSet,setSize,maxLength-1);
}
free(str);
}
void printAllCombinations(char *charSet,int setSize,int maxLength)
{
_printAllCombinations("",charSet,setSize,maxLength);
}
int main()
{
char charSet[10]={'0','1','2','3','4','5','6','7','8','9'};
printAllCombinations(charSet,10,3);
printf("Count: %d\n",count);
return 0;
}