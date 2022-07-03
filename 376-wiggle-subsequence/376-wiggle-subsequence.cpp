class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()==1 || nums.size()==0) return nums.size();
        int count=0;
        int prevDiff,diff;
        prevDiff=nums[1]-nums[0];
        
        if(prevDiff!=0) count=2;
        else count=1;
        for(int i=2;i<nums.size();i++)
        {
            diff=nums[i]-nums[i-1];
            if(diff>0 && prevDiff<=0 || diff<0 && prevDiff>=0)
            {
                count++;
                prevDiff=diff;
            }
            
        }
        return count;
    }
};