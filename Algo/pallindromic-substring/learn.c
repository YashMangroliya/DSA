#include<stdio.h>
#include<string.h>
int main()
{
char *str="levvel";
int len,i,j,len2,si,ei;
len=strlen(str);
len2=len*2+1;
char str2[len2];
int lengths[len2];
char c='!';
for(i=0,j=0;i<len;i++,j+=2)
{
str2[j]='!';
str2[j+1]=str[i];
}
str2[j]='!';

for(i=0;i<len2;i++)
{
si=i-1;
ei=i+1;
while(si>=0 && ei<len2 && str2[si]==str2[ei])
{
si--;
ei++;
}
si++;
ei--;
lengths[i]=ei-si+1;
}



printf("str2: ");
for(i=0;i<len2;i++) printf("%c",str2[i]);
printf("\n");
printf("lengths: ");
for(i=0;i<len2;i++) printf("%d ",lengths[i]);
printf("\n");



return 0;
}