class Solution {
public:
    int dp[102][102];
    int path(int i,int j,int m,int n)
    {
        if(i>=m || j>=n) return 0;
        if(i==m-1 && j==n-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int down = path(i+1,j,m,n);
        int right = path(i,j+1,m,n);
        dp[i][j]=down+right;
        return dp[i][j];
    }
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        int count = path(0,0,m,n);
        return count;
    }
};