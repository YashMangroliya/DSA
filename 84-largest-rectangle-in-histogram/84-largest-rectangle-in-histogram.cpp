class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        // brute force 
        
        // int n=heights.size();
        // int left,right,i,j,k,height;
        // int maxArea=0,area;
        // for(i=0;i<n;i++)
        // {
        //     height=heights[i];
        //     for(k=i-1;k>=0;k--)
        //     {
        //         if(heights[k]<height) break;
        //     }
        //     left=k+1;
        //     for(k=i+1;k<n;k++)
        //     {
        //         if(heights[k]<height) break;
        //     }
        //     right=k-1;
        //     area=(right-left+1)*height;
        //     maxArea=max(area,maxArea);
        // }
        // return maxArea;
        
        // Optimized Solution
        
//         int n=heights.size();
//         vector<int> left(n,0); // for the previous lesser element
//         vector<int> right(n,n-1);  // for the next lesser element
//         // here I have initialized a vector of size n and have initilized every element by n-1
//         stack<int> s;
        
//         int i,height,area,maxArea=0;
//         // to populate left vector with previous lesser elements
//         for(i=0;i<n;i++)
//         {
//             height=heights[i];
//             while(!s.empty() && heights[s.top()]>=height)
//             {
//                 s.pop();
//             }
//             if(!s.empty())
//             {
//                 left[i]=s.top()+1;
//             }
//             s.push(i);
//         }
//         while(!s.empty()) s.pop();
        
//         // to populate right vector with next lesser elements
//         for(i=n-1;i>=0;i--)
//         {
//             height=heights[i];
//             while(!s.empty() && heights[s.top()]>=height)
//             {
//                 s.pop();
//             }
//             if(!s.empty())
//             {
//                 right[i]=s.top()-1;
//             }
//             s.push(i);            
//         }
        
//         for(i=0;i<n;i++)
//         {
//             area=(right[i]-left[i]+1)*heights[i];
//             maxArea=max(maxArea,area);
//         }
//         return maxArea;
        
        
        int maxArea,height,width;
        int n=heights.size();
        stack<int> s;
        
        for(int i=0;i<=n;i++)
        {
            while(!s.empty() && (i==n || heights[s.top()]>=heights[i]))
            {
                height=heights[s.top()];
                s.pop();
                if(s.empty()) width=i;
                else width=i-s.top()-1;
                maxArea=max(maxArea,width*height);
            }
            s.push(i);
        }
        return maxArea;
    }
};