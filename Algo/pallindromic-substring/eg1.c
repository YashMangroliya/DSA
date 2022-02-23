// here i will implement logic to find longest pallimdrop substring from a string
// Using Brute Force
#include<iostream>
using namespace std;
string getLongestPallindromicSubString(string s)
{
string subString;
int length,i,j,e,f;
length=s.length();
bool flag=false;
for(i=0;i<length-1;i++)
{
for(j=i;j<length;j++)
{
flag=true;
e=i;
f=j;
while(e<f)
{
if(s[e]!=s[f])
{
flag=false;
break;
}
e++;
f--;
}
if(flag)
{
if(j-i+1>subString.length()) subString=s.substr(i,j-i+1);  // longest ko store karne ka logic
}
}
}
return subString;
}
int main()
{
string s;
cin>>s;
cout<<getLongestPallindromicSubString(s)<<endl;
return 0;
}
