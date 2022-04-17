// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    bool isInterleave(string A, string B, string C) 
    {
        if(A.length()+B.length()!=C.length()) return false;
        bool dp[A.length()+1][B.length()+1];
        int i,j;
        for(i=0;i<A.length()+1;i++)
        {
            for(j=0;j<B.length()+1;j++)
            {
                if(i==0 && j==0)
                {
                    dp[0][0]=true;
                }
                else if(i==0)
                {
                    (B[j-1]==C[i+j-1]) ? dp[i][j]=dp[i][j-1] : dp[i][j]=false;
                }
                else if(j==0)
                {
                    (A[i-1]==C[i+j-1]) ? dp[i][j]=dp[i-1][j] : dp[i][j]=false;
                }
                else
                {
                    dp[i][j] = false; // for default value
                    if(A[i-1]==C[i+j-1])
                    {
                        dp[i][j]=dp[i-1][j];
                    }
                    if(!dp[i][j] && B[j-1]==C[i+j-1])
                    {
                        dp[i][j]=dp[i][j-1];
                    }
                }
            }
        }
        return dp[A.length()][B.length()];
    }

};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}  // } Driver Code Ends