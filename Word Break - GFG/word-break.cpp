// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    unordered_set<string> set1;
    
    int rec(string& A, int index)
    {
        if(index==A.length()) return 1;
        int i,k;
        string s;
        for(i=index;i<A.length();i++)
        {
            s=A.substr(index,i-index+1);
            if(set1.find(s)!=set1.end())
            {
                k=i+1;
                if(rec(A,i+1)) return 1;
            }
        }
        if(k==A.length()) return 1;
        else return 0;
    }
    
    int wordBreak(string A, vector<string> &B) {
        for(string s : B) set1.insert(s);
        return rec(A,0);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends