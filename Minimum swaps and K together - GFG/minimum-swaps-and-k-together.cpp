// { Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        int count=0;
        int lmin,gmin,i,j;
        gmin=n+1;
        for(i=0;i<n;i++)
        {
            if(arr[i]<=k) count++;
        }
        lmin=0;
        for(i=0;i<count;i++) if(arr[i]>k) lmin++;
        gmin=lmin;
        for(i=0,j=count;j<n;i++,j++)
        {
            if(arr[i]>k) lmin--;
            if(arr[j]>k) lmin++;
            gmin=std::min(gmin,lmin);
        }
        
        return gmin;
    }
};


// { Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}
  // } Driver Code Ends