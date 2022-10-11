class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        int lesser[n];
        int greater[n];
        int mini,maxi;
        mini=0;
        lesser[0]=-1;
        for(int i=0;i<n-1;i++)
        {
            if(nums[mini]<nums[i])
            {
                lesser[i]=mini;
            }
            else
            {
                mini=i;
                lesser[i]=-1;
            }
        }
        
        maxi=n-1;
        greater[n-1]=-1;
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]<nums[maxi])
            {
                greater[i]=maxi;
                if(lesser[i]!=-1) return true;
            }
            else
            {
                maxi=i;
                greater[i]=-1;
            }
        }
        
        // for(int i=0;i<n;i++)
        // {
        //     if(lesser[i]!=-1 && greater[i]!=-1) return true;
        // }
        return false;
    }
};