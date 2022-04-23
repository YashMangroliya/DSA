class Solution {
public:
    unordered_set<string> set1;
    
    int rec(string& A, int index, int dp[])
    {
        if(index==A.length()) return 1;
        if(dp[index]!=-1) return dp[index];
        int i,k;
        string s;
        for(i=index;i<A.length();i++)
        {
            s=A.substr(index,i-index+1);
            if(set1.find(s)!=set1.end())
            {
                k=i+1;
                if(rec(A,i+1,dp))
                {
                    dp[index]=1;
                    return 1;
                }
            }
        }
        if(k==A.length())
        {
            dp[index]=1;
            return 1;
        }
        else 
        {
            dp[index]=0;
            return 0;
        }
    }
    
    // bool rec(string& A, int index)
    // {
    //     if(index==-1) return true;
    //     int i,k;
    //     string s;
    //     for(i=index;i>=0;i--)
    //     {
    //         s=A.substr(i,index-i+1);
    //         if(set1.find(s)!=set1.end())
    //         {
    //             k=i-1;
    //             if(rec(A,i-1)) return true;
    //         }
    //     }
    //     if(k==-1) return true;
    //     else return false;
    // }
    

    bool wordBreak(string s, vector<string>& wordDict) {
        int dp[s.length()+1];
        memset(dp,-1,sizeof(dp));
        for(string ss : wordDict) set1.insert(ss);
        return rec(s,0,dp)==1;
    }
};