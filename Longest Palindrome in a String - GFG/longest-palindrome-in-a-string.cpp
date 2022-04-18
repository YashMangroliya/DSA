// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
        int len=s.length();
        bool mat[len][len];
        int i,j,k,count;
        string ans;
        count=1;
        ans=s[0];
        for(i=0;i<len;i++) mat[i][i]=true;
        for(i=0;i<len-1;i++) 
        {
            if(s[i]==s[i+1])
            {
                mat[i][i+1]=true;
                if(count < 2)
                {
                    count = 2;
                    ans = s.substr(i,2);
                }
            }
            else{
                mat[i][i+1]=false;
            }
        }
        
        k=2;
        while(k<len)
        {
            for(i=0;i+k<len;i++)
            {
                if(s[i]==s[i+k]){
                    mat[i][i+k] = mat[i+1][i+k-1];
                    if(mat[i][i+k] && k+1 > count)
                    {
                        count = k+1;
                        ans = s.substr(i,k+1);
                    }
                }
                else mat[i][i+k]=false;
            }
            k++;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends