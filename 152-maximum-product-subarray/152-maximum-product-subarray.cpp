class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxSoFar=nums[0],minSoFar=nums[0],temp,maxOverall=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            temp=maxSoFar;
            maxSoFar=max({nums[i],maxSoFar*nums[i],minSoFar*nums[i]});
            minSoFar=min({nums[i],temp*nums[i],minSoFar*nums[i]});
            maxOverall=max(maxSoFar,maxOverall);
        }
        return maxOverall;
    }
};