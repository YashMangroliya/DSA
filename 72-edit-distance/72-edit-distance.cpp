class Solution {
public:
    int dp[502][502];
    int rec(string& s, string& t, int i, int j)
    {
        if(j>=t.length()) {
            return s.length()-i;
        }
        if(i>=s.length()) {
            return t.length()-j;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int ans;
        if(s[i]==t[j])
        {
            ans = rec(s,t,i+1,j+1);
        }
        else
        {
            int count1,count2,count3;
            count1 = 1 + rec(s,t,i,j+1);  // insert
            
            count2 = 1 + rec(s,t,i+1,j);  // remove
            
            count3 = 1 + rec(s,t,i+1,j+1);  // replace
            ans = min({count1,count2,count3});
        }
        dp[i][j]=ans;
        return ans;
    }

    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        return rec(word1,word2,0,0);
    }
};