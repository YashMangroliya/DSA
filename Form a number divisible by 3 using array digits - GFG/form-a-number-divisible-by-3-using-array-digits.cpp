// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int isPossible(int N, int arr[]) {
        // code here
        int sum=0,localSum;
        int i=0;
        int num;
        while(i<N)
        {
            num=arr[i];
            localSum=0;
            while(num>0)
            {
                localSum+=(num%10);
                num=num/10;
            }
            sum+=localSum;
            i++;
        }
        if(sum%3==0) return 1;
        else return 0;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution ob;
        cout << ob.isPossible(N, arr) << endl;
    }
    return 0;
}  // } Driver Code Ends