class Solution {
public:
    
    int dp[102][102];
    bool isInterleave_(string A, string B, string C,int i,int j) {
        
        if(i==A.length() && j==B.length()) return true;  // Base case
        bool flagA,flagB;
        int k=i+j;
        if(dp[i][j]!=-1) return dp[i][j];
        if(A[i]==C[k]){
            flagA = isInterleave_(A,B,C,i+1,j);
            if(flagA)
            {
                dp[i][j]=1;
                return true;
            }
        }
        if(B[j]==C[k]) {
            flagB = isInterleave_(A,B,C,i,j+1);
            if(flagB) 
            {
                dp[i][j]=1;
                return true;
            }
        }
        dp[i][j]=0;
        return false;
        
    }
    
    bool isInterleave(string A, string B, string C) {
        if(A.length()+B.length()!=C.length()) return false;
        // vector<vector<int>> dp(A.length()+1,vector<int>(B.length()+1,0));
        
        // memset(dp, -1,sizeof(dp));
        for(int i=0;i<A.length()+1;i++)
        {
            for(int j=0;j<B.length()+1;j++) dp[i][j]=-1;
        }
        //  we will store 1 for possible and -1 for not possible, 0 is default value
        return isInterleave_(A,B,C,0,0);
    }
};