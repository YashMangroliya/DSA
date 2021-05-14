#include<map>
using namespace std;
int main()
{
map<int,int> m;
m.insert(pair<int,int>(10,1));
m.insert(pair<int,int>(10,2));
m.insert(pair<int,int>(10,3));
printf("%d",m.size());
cout<<5;
return 0;
}