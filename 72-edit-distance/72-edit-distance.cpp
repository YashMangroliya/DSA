class Solution {
public:
//     Method 1
    
    int dp[502][502];
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

    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        return rec(word1,word2,word1.length()-1,word2.length()-1);
    }
    
    
    // Method 2
//     int minDistance(string s, string t) {
        
//     }
};