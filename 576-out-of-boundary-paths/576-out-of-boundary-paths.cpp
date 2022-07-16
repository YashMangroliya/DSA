class Solution {
public:
    long dp[52][52][52];
    long rec(int m,int n,int remMove,int row,int col)
    {
        if(row<0 || col<0 || row>=m || col>=n)
        {
            return 1;
        }
        if(remMove<=0) return 0;
        if(dp[row][col][remMove]!=-1) return dp[row][col][remMove];
        long val1 = rec(m,n,remMove-1,row+1,col);
        long val2 = rec(m,n,remMove-1,row,col+1);
        long val3 = rec(m,n,remMove-1,row-1,col);
        long val4 = rec(m,n,remMove-1,row,col-1);
        dp[row][col][remMove] = (val1+val2+val3+val4)%1000000007;
        return dp[row][col][remMove];
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        long count = rec(m,n,maxMove,startRow,startColumn);
        return count % 1000000007;
    }
};