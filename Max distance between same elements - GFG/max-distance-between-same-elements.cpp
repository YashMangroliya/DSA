// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    // your task is to complete this function
    int maxDistance(int arr[], int n)
    {
        int maxDistance=0;
        int i,j;
        i=0;
        while(i<n && (n-i)>maxDistance)
        {
            j=n-1;
            while(arr[j]!=arr[i] && (j-i)>maxDistance) j--;
            if(arr[i]==arr[j] && (j-i)>maxDistance) maxDistance=j-i;
            i++;
        }
        return maxDistance;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.maxDistance(arr,n)<<endl;
    }
    return 0;
}  // } Driver Code Ends