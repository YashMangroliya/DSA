class Solution {
public:
    
    int find(vector<int>& nums,int target,int dp[])
    {
        if(target==0) return 1;
        if(target<0) return 0;
        if(dp[target]!=-1) return dp[target];
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            ans+=find(nums,target-nums[i],dp);
        }
        dp[target]=ans;
        return ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int dp[1002];
        memset(dp,-1,sizeof(dp));
        return find(nums,target,dp);
    }
};