// This is question 1:
// We have to find whether the array contains any duplicate number
#include<iostream>
#include<set>
using namespace std;
int containsDuplicate(set<int> s,int collectionSize)
{
return s.size()!=collectionSize;
}
int main()
{
cout<<(containsDuplicate({1,2,3,4,5,4},6)==1?"True":"False")<<endl;
return 0;
}