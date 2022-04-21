// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	
	vector<string> ans;
	void permutations(int swi,string s)
	{
	    char c;
	    if(swi==s.length()-1)
	    {
	        ans.push_back(s);
	        return;
	    }
	    int i,k;
	    for(i=swi;i<s.length();i++)
	    {
	        // code for not printing duplicate permutation starts here (for understanding take s='YAAS')
	        for(k=swi;k<i;k++) if(s[k]==s[i]) break;
	        if(k<i) continue;
	        // code for not printing duplicate permutation ends here (for understanding take s='YAAS')
	        c=s[i];
	        s[i]=s[swi];
	        s[swi]=c;
	        permutations(swi+1,s);
	        c=s[i];
	        s[i]=s[swi];
	        s[swi]=c;
	    }
	}
	
	vector<string>find_permutation(string s)
	{
	    permutations(0,s);
	    sort(ans.begin(),ans.end());
	    return ans;
	}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends