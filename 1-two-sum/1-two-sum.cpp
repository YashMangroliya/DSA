class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vec;
        int i=0,j=0;
        int numsSize=nums.size();
        for(j=0;j<numsSize;j++)
        {
            for(i=j+1;i<numsSize;i++)
            {
                if(nums[j]+nums[i]==target)
                {
                    vec.push_back(j);
                    vec.push_back(i);
                    return vec;
                }
            }
        }
        return vec;
    }
};