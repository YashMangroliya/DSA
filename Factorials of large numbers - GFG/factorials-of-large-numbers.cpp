// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> toVector(int n)
    {
        vector<int> v;
        while(n>0)
        {
            v.push_back(n%10);
            n/=10;
        }
        reverse(v.begin(),v.end());
        return v;
    }
    vector<int> multiply_(vector<int> num1,int num2)
    {
        vector<int> ans;
        int carry=0,m;
        for(int i=num1.size()-1;i>=0;i--)
        {
            m=num2*num1[i]+carry;
            ans.push_back(m%10);
            m=m/10;
            carry=m;
        }
        vector<int> remainingCarry=toVector(carry);
        for(int i=remainingCarry.size()-1;i>=0;i--)
        {
            ans.push_back(remainingCarry[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    vector<int> factorial(int N){
        vector<int> num1,ans;
        int num2;
        num1=toVector(N);
        num2=N-1;
        if(N==1) return num1;
        while(num2>=1)
        {
            ans=multiply_(num1,num2);
            num1=ans;
            num2--;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends