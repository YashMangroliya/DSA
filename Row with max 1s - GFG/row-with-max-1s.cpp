// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int index=m,count,i,j;
	    int ii=-1;
	    for(i=0;i<n;i++)
	    {
	        for(j=index-1;j>=0;j--)
	        {
	            if(arr[i][j]==0){
	                break;
	            }
	        }
	        if(j+1<index)
	        {
	            index=j+1;
	            ii=i;
	        }
	    }
	    return ii;
	}
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends