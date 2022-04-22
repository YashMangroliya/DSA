// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:

    // we are coming from right to left (i.e. from end to start) of strings
    // int dp[102][102];
    // int rec(string& s, string& t, int i, int j)
    // {
    //     if(j<0) {
    //         return i+1;
    //     }
    //     if(i<0) {
    //         return j+1;
    //     }
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int ans;
    //     if(s[i]==t[j])
    //     {
    //         ans = rec(s,t,i-1,j-1);
    //     }
    //     else
    //     {
    //         int count1,count2,count3;
    //         count1 = 1 + rec(s,t,i,j-1);  // insert
            
    //         count2 = 1 + rec(s,t,i-1,j);  // remove
            
    //         count3 = 1 + rec(s,t,i-1,j-1);  // replace
    //         ans = min({count1,count2,count3});
    //     }
    //     dp[i][j]=ans;
    //     return ans;
    // }


    // int editDistance(string s, string t) {
    //     memset(dp,-1,sizeof(dp));
    //     return rec(s,t,s.length()-1,t.length()-1);
    // }
    
    int editDistance(string s, string t) {
        int n=s.length()+1,m=t.length()+1;
        int dp[n][m];
        memset(dp,0,sizeof(dp));
        int i,j;
        // below code is written by observing base cases
        for(i=0;i<n;i++) dp[i][0]=i;
        for(j=0;j<m;j++) dp[0][j]=j;
        // above code is written by observing base cases
        
        int count1,count2,count3;
        for(i=1;i<n;i++)
        {
            for(j=1;j<m;j++)
            {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    count1 = dp[i][j-1];
                    count2 = dp[i-1][j];
                    count3 = dp[i-1][j-1];
                    dp[i][j] = min({count1,count2,count3}) + 1;
                }
            }
        }
        return dp[n-1][m-1];
    }

    
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends