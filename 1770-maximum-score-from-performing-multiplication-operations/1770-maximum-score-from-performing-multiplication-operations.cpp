// TLE
// class Solution {
// public:
//     // si-> start index, ei-> end index, mi-> multiplier index
//     int ans=INT_MIN;
//     void helper(vector<int>& nums,vector<int>& multipliers,int si,int ei,int mi,int score) 
//     {
//         if(mi==multipliers.size())
//         {
//             ans=max(ans,score);
//             return;
//         }
//         helper(nums,multipliers,si+1,ei,mi+1,score+multipliers[mi]*nums[si]);
//         helper(nums,multipliers,si,ei-1,mi+1,score+multipliers[mi]*nums[ei]);
//     }
//     int maximumScore(vector<int>& nums, vector<int>& multipliers) {
//         helper(nums,multipliers,0,nums.size()-1,0,0);
//         return ans;
//     }
// };

class Solution {
public:
    int helper(vector<int>& nums,vector<int>& M,int si,int ei,int mi,vector<vector<int>>& dp)
    {
        if(mi==M.size()) return 0;
        if(dp[mi][si]!=INT_MIN) return dp[mi][si];
        int left=M[mi]*nums[si] + helper(nums,M,si+1,ei,mi+1,dp);
        int right=M[mi]*nums[ei] + helper(nums,M,si,ei-1,mi+1,dp);
        return dp[mi][si]= max(left,right);
    }
    
    int maximumScore(vector<int>& nums, vector<int>& M) {   
        vector<vector<int>> dp(M.size(),vector<int>(M.size(),INT_MIN));

        return helper(nums,M,0,nums.size()-1,0,dp);
    }
};