class Solution {
public:  //  226
    int helper(int i,string s,int n,int dp[])
    {
        if(i>=n) 
        {
            return 1;
        }
        if(dp[i]!=-1) return dp[i];
        int a,b,num,first=0,second=0;
        a=s[i]-'0';
        if(a!=0) 
        {
            first = helper(i+1,s,n,dp);
        }
        else return 0;
        if(i+1<n && a!=0)
        {
            b=s[i+1]-'0';
            num=a*10+b;
            if(num>=10 && num<=26)
            {
                second = helper(i+2,s,n,dp);
            }
        }
        return dp[i]=first+second;
    }
    int numDecodings(string s) {
        int dp[s.length()];
        memset(dp,-1,sizeof(dp));
        return helper(0,s,s.length(),dp);
        
    }
};