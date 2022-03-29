// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    void segregateElements(int arr[],int n)
    {
        // Your code goes here
        int arr2[n];
        int l=0,r=n-1,i=0;
        int posCount=0;
        while(i<n)
        {
            if(arr[i]<0)
            {
                arr2[r]=arr[i];
                r--;
            }
            else
            {
                arr2[l]=arr[i];
                l++;
                posCount++;
            }
            i++;
        }
        reverse(arr2+posCount,arr2+n);
        i=0;
        while(i<n)
        {
            arr[i]=arr2[i];
            i++;
        }
    }
};

// { Driver Code Starts.
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		ob.segregateElements(a,n);
		
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
		cout<<endl;
	}
}
  // } Driver Code Ends