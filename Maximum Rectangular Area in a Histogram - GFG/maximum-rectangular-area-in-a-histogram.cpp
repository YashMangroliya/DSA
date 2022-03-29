// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long heights[], int n)
    {
                
        vector<int> left(n,0); // for the previous lesser element
        vector<int> right(n,n-1);  // for the next lesser element
        // here I have initialized a vector of size n and have initilized every element by n-1
        stack<long long> s;
        
        int i,height;
        long long area,maxArea=0;
        // to populate left vector with previous lesser elements
        for(i=0;i<n;i++)
        {
            height=heights[i];
            while(!s.empty() && heights[s.top()]>=height)
            {
                s.pop();
            }
            if(!s.empty())
            {
                left[i]=s.top()+1;
            }
            s.push(i);
        }
        while(!s.empty()) s.pop();
        
        // to populate right vector with next lesser elements
        for(i=n-1;i>=0;i--)
        {
            height=heights[i];
            while(!s.empty() && heights[s.top()]>=height)
            {
                s.pop();
            }
            if(!s.empty())
            {
                right[i]=s.top()-1;
            }
            s.push(i);            
        }
        
        for(i=0;i<n;i++)
        {
            area=(right[i]-left[i]+1)*heights[i];
            maxArea=max(maxArea,area);
        }
        return maxArea;
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends