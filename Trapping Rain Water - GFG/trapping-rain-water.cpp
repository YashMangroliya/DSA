// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        long long total=0;
        int l,r,rmax,lmax;
        lmax=arr[0];
        rmax=arr[n-1];
        for(l=0,r=n-1;l<=r;)
        {
            if(arr[l]<=arr[r])
            {
                if(arr[l]>lmax) lmax=arr[l];
                else total=total+(lmax-arr[l]);
                l++;
            }
            else
            {
                if(arr[r]>rmax) rmax=arr[r];
                else total=total+(rmax-arr[r]);
                r--;
            }
        }
        return total;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends