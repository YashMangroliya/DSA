class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0,minLength=nums.size()+1,start=0,end=0;
        while(end<nums.size())
        {
            while(sum<target && end<nums.size())
            {
                sum+=nums[end];
                end++;
            }
            while(sum>=target && start<nums.size())
            {
                if(end-start < minLength)
                {
                    minLength=end-start;
                }
                sum-=nums[start];
                start++;
            }
        }
        if(minLength==nums.size()+1) return 0;
        return minLength;
    }
};