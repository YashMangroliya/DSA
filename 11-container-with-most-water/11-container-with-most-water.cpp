class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        // time limit exceeded
        
        // int area,mArea,i,j,sheight,eheight;
        // mArea=0;
        // int size=heights.size();
        // for(i=0;i<size-1;i++)
        // {
        //     for(j=i+1;j<size;j++)
        //     {
        //         mArea=max(mArea,min(heights[i],heights[j])*(j-i));
        //     }
        // }
        // return mArea;
        
        int s,e,maxArea=0;
        int size=heights.size();
        s=0;
        e=size-1;
        
        while(s<e)
        {
            maxArea=max(maxArea,min(heights[s],heights[e])*(e-s));
            if(heights[s]<heights[e]) s++;
            else e--;
        }
        
        return maxArea;
    }
};