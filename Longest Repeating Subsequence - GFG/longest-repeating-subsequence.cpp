// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
	int LongestRepeatingSubsequence(string str){
	    string text1,text2;
	    text1=str;
	    text2=str;
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
                if(i!=j && text1[i-1]==text2[j-1])
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

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends