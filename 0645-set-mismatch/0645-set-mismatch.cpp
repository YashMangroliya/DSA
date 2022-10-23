class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        unordered_set<int> set1;
        vector<int> ans(2);
        for(int i=0;i<nums.size();i++)
        {
            if(set1.count(nums[i])>0) ans[0]=nums[i];
            else set1.insert(nums[i]);
        }
        for(int i=1;i<=nums.size();i++)
        {
            if(set1.count(i)==0)
            {
                ans[1]=i;
                return ans;
            }
        }
        return ans;
    }
};