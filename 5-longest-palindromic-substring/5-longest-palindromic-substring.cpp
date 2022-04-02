class Solution {
public:
    string longestPalindrome(string s) {
        
        int n=s.length();
        int dp[n][n];
        int longest=0;
        int i,j,si=0,ei=0;
        for(i=0;i<n;i++) dp[i][i]=1;
        for(i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1]=1;
                if(2>longest)
                {
                    longest=2;
                    si=i;
                    ei=i+1;
                }
            }
            else dp[i][i+1]=0;
        }
        
        for(j=2;j<n;j++)
        {
            for(i=0;i+j<n;i++)
            {
                if(s[i]==s[i+j] && dp[i+1][i+j-1]==1)
                {
                    dp[i][i+j]=1;
                    if((i+j)-i+1>longest)
                    {
                        longest=(i+j)-i+1;
                        si=i;
                        ei=(i+j);
                    }
                }
                else dp[i][i+j]=0;
            }
        }
        
        return s.substr(si,ei-si+1);
        
        
        
        
        
        // int longest=0,k,l,si,ei;
        // for(int i=0;i<s.length()-1;i++)
        // {
        //     for(int j=s.length()-1;j>i;j--)
        //     {
        //         k=i;
        //         l=j;
        //         while( k<l && s[k]==s[l] )
        //         {
        //             k++;
        //             l--;
        //         }
        //         if(k>=l)
        //         {
        //             if(j-i+1>longest)
        //             {
        //                 longest=j-i+1;
        //                 si=i;
        //                 ei=j;
        //             }
        //             break;
        //         }
        //     }
        // }
        // cout<<si<<endl;
        // cout<<ei<<endl;
        // if(longest!=0) return s.substr(si,ei-si+1);
        // return s.substr(0,1);
    }
};