class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        long hmax,vmax,curr,prev;
        hmax=vmax=INT_MIN;
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        prev=0;
        for(int i=0;i<horizontalCuts.size();i++)
        {
            curr=horizontalCuts[i];
            hmax = max(hmax,abs(curr-prev));
            prev=curr;
        }
        curr=h;
        hmax = max(hmax,curr-prev);
        prev=0;
        for(int i=0;i<verticalCuts.size();i++)
        {
            curr=verticalCuts[i];
            vmax = max(vmax,abs(curr-prev));
            prev=curr;
        }
        curr=w;
        vmax = max(vmax,curr-prev);
        vmax=vmax%1000000007;
        hmax=hmax%1000000007;
        return vmax*hmax % 1000000007;
    }
};