class Solution {
public:
    void findSubsets(vector<int> & nums,int index,vector<int> & ds,vector<vector<int>> &ans)
    {
        if(index==nums.size())
        {
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[index]);
        findSubsets(nums,index+1,ds,ans);
        ds.pop_back();
        findSubsets(nums,index+1,ds,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        findSubsets(nums,0,ds,ans);
        return ans;
    }
};