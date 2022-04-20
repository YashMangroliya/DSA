class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.length()+1;
        int n=text2.length()+2;
        int dp[m][n];
        int i,j;
        for(i=0;i<m;i++)
        {
            dp[i][0]=0;
        }
        for(j=0;j<n;j++)
        {
            dp[0][j]=0;
        }
        for(i=1;i<m;i++)
        {
            for(j=1;j<n;j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m-1][n-1];
    }
};