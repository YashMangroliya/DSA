// here I will implement logic to find longest pallindrome substring
// Using Dynamic Programming (Memoization)
#include<stdio.h>
struct pallindrome
{
int length;
char * pallindrome;
};

struct pallindrome getLongestPallindrome(char *str)
{
char *p,*q;
int i,j,k,size,si,largest;
q=str;
p=str;
while(*q) q++;  // q next to last byte pe chala jayega
size=q-p;

int store[size][size]; // taking a boolean matrix of size  'size*size'
// now what we will do is matrix k lower half me false daal dege
for(i=0;i<size;i++)
{
for(j=0;j<=i;j++)
{
if(i==j) store[i][j]=1;   // 1 logically means true
else store[i][j]=0;       // 0 logically means false
}
}
largest=0;
for(k=1;k<size;k++)
{
for(i=0,j=k;j<size;i++,j++)
{
if(str[i]==str[j])
{
if(store[i+1][j-1] || i+1==j)  // 2nd condition is for situations like 'aa'
{
store[i][j]=1;
if(j-i+1>largest)
{
largest=j-i+1;
si=i;
}
}
else store[i][j]=0;
}
else
{
store[i][j]=0;
}
}
}

struct pallindrome pp;
pp.length=largest;
pp.pallindrome=(str+si);
return pp;
}


int main()
{
struct pallindrome p;
p=getLongestPallindrome("level");
printf("%d\n",p.length);
for(int i=0;i<p.length;i++) printf("%c",*(p.pallindrome+i));
return 0;
}