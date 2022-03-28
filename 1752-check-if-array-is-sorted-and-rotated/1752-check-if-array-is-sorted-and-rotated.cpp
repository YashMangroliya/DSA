class Solution {
public:
    bool check(vector<int>& nums) {
        int size=nums.size();
        int e,f,i,j;
        i=0;
        for(j=1;j<size;j++) 
        {
            if(nums[j]<nums[i]) i=j;
            else if(nums[j]==nums[i] && nums[j]==nums[0] && nums[j]!=nums[j-1]) i=j;
        }
        for(e=i,f=e+1;true;e++,f++)
        {
            if(e>=size) e=0;
            if(f>=size) f=0;
            if(nums[e]>nums[f]) break;
            if(f==i) break;
        }
        return f==i;
    }
};