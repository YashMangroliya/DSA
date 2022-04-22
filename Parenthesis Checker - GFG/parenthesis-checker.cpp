// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> stk;
        for(char c : x)
        {
            if(c=='(' || c=='{' || c=='[') stk.push(c);
            else if(c==')') {
                if(stk.empty() || stk.top()!='(') return false;
                stk.pop();
            }
            else if(c=='}') {
                if(stk.empty() || stk.top()!='{') return false;
                stk.pop();
            }
            else if(c==']') {
                if(stk.empty() || stk.top()!='[') return false;
                stk.pop();
            }
        }
        return stk.empty();
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends