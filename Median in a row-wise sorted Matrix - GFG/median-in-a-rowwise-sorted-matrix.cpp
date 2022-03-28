// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{   
public:

    int countSmallerThanOrEqualsToMid(vector<int> &row,int mid){
        int l=0,h=row.size()-1;
        while(l<=h)
        {
            int md=(l+h)/2;
            if(row[md]<=mid)
            {
                l=md+1;
            }
            else{
                h=md-1;
            }
        }
        return l;
    }

    int median(vector<vector<int>> &matrix, int n, int m){
        int low=INT_MAX,high=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(matrix[i][0]<low) low=matrix[i][0];
            if(matrix[i][m-1]>high) high=matrix[i][m-1];
        }
        int mid,count;
        while(low<=high)
        {
            mid=(high+low)>>1;
            count=0;
            for(int i=0;i<n;i++)
            {
                count+=countSmallerThanOrEqualsToMid(matrix[i],mid);
            }
            if(count <= (n*m)/2) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}  // } Driver Code Ends