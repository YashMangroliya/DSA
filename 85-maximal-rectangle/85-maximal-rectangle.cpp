class Solution {
public:
    
    int getMaxAreaOfReactagleInHistogram(vector<int> heights)
    {
        int n=heights.size();
        stack<int> s;
        int height,width,maxArea;
        for(int i=0;i<=n;i++)
        {
            while(!s.empty() && (i==n || heights[s.top()]>=heights[i]))
            {
                height=heights[s.top()];
                s.pop();
                if(s.empty()) width=i;
                else width=i-s.top()-1;
                maxArea=max(maxArea,height*width);
            }
            s.push(i);
        }
        return maxArea;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> v(m,0);
        int maxArea=0;
        int i,j;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(matrix[i][j]=='1')
                {
                    v[j]++;
                }
                else {
                    v[j]=0;
                }
            }
            maxArea=max(maxArea,getMaxAreaOfReactagleInHistogram(v));
        }
        return maxArea;
    }
};