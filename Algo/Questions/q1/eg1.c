// This is question 1:
// We have to find whether the array contains any duplicate number
#include<stdio.h>
int containsDuplicate(int *numbers,int size)
{
int e,f;
for(e=1;e<size;e++)
{
for(f=0;f<e;f++)
{
if(numbers[e]==numbers[f]) return 1;
}
}
return 0;
}
int main()
{
int x[5]={1,2,3,4,2};
printf("%s\n",containsDuplicate(x,5)==1?"True":"False");
return 0;
}