// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            
            //This is also right solution.
            // vector<int> v;
            // vector<int> ans;
            // int i;
            // v.push_back(A[0]);
            // for(i=1;i<n1;i++)
            // {
            //     if(A[i-1]==A[i]) continue;
            //     v.push_back(A[i]);
            // }
            // v.push_back(B[0]);
            // for(i=1;i<n2;i++)
            // {
            //     if(B[i-1]==B[i]) continue;
            //     v.push_back(B[i]);
            // }
            // v.push_back(C[0]);
            // for(i=1;i<n3;i++)
            // {
            //     if(C[i-1]==C[i]) continue;
            //     v.push_back(C[i]);
            // }
            // sort(v.begin(),v.end());
            // for(i=0;i<v.size()-2;i++)
            // {
            //     if(v[i]==v[i+1] && v[i]==v[i+2]) ans.push_back(v[i]);
            // }
            // return ans;

            vector<int> ans;
            int i1,i2,i3;
            for(i1=0,i2=0,i3=0 ; i1<n1 && i2<n2 && i3<n3;)
            {
                if(A[i1]==B[i2] && B[i2]==C[i3]) if(ans.size()==0 || ans.back()!=A[i1]) ans.push_back(A[i1]);
                if(A[i1]<B[i2]) i1++;
                else if(B[i2]<C[i3]) i2++;
                else i3++;
            }
            return ans;
        }

};

// { Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}  // } Driver Code Ends