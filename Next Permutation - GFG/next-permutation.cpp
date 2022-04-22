// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        int ind1=-1;
        int ind2=-1;
        for(int i=N-2;i>=0;i--)
        {
            if(arr[i]<arr[i+1])
            {
                ind1=i;
                break;
            }
        }
        if(ind1==-1)
        {
            sort(arr.begin(),arr.end());
            return arr;
        }
        for(int i=N-1;i>ind1;i--)
        {
            if(arr[i]>arr[ind1])
            {
                ind2=i;
                break;
            }
        }
        swap(arr[ind1],arr[ind2]);
        reverse(arr.begin()+ind1+1,arr.end());
        return arr;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends