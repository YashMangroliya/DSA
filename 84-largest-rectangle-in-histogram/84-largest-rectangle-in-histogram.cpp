class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> left(n,0); // for the previous lesser element
        vector<int> right(n,n-1);  // for the next lesser element
        // here I have initialized a vector of size n and have initilized every element by n-1
        stack<int> s;
        
        int i,height,area,maxArea=0;
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
        // for(auto j: left) cout<<j<<" ";
        // cout<<endl;
        
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
        // for(auto j: right) cout<<j<<" ";
        // cout<<endl;
        for(i=0;i<n;i++)
        {
            area=(right[i]-left[i]+1)*heights[i];
            maxArea=max(maxArea,area);
        }
        return maxArea;
    }
};