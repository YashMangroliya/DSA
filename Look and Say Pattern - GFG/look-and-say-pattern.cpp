// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    string lookandsay(int n) {
        // code here
        string s="1";
        string newStr;
        int count;
        char prevChar;
        while(n>1)
        {
            prevChar=s[0];
            count=1;
            newStr="";
            for(int i=1;i<s.length();i++)
            {
                if(s[i]==prevChar) count++;
                else 
                {
                    newStr+=(count+48);
                    newStr+=prevChar;
                    prevChar=s[i];
                    count=1;
                }
            }
            newStr+=(count+48);
            newStr+=prevChar;
            s=newStr;
            n--;
        }
        return s;

    }   
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution obj;
        cout<<obj.lookandsay(n)<<endl;
    }
    return 0;
}  // } Driver Code Ends