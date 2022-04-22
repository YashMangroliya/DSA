// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:

    int dp[102][102];
    int rec(string& s, string& t, int i, int j)
    {
        if(j<0) {
            return i+1;
        }
        if(i<0) {
            return j+1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int ans;
        if(s[i]==t[j])
        {
            ans = rec(s,t,i-1,j-1);
        }
        else
        {
            int count1,count2,count3;
            count1 = 1 + rec(s,t,i,j-1);  // insert
            
            count2 = 1 + rec(s,t,i-1,j);  // remove
            
            count3 = 1 + rec(s,t,i-1,j-1);  // replace
            ans = min({count1,count2,count3});
        }
        dp[i][j]=ans;
        return ans;
    }

    int editDistance(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return rec(s,t,s.length()-1,t.length()-1);
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