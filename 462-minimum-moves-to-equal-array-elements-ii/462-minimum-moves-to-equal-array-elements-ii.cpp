class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        int median,n,sum;
        sort(nums.begin(),nums.end());
        n=nums.size();
        if(nums.size()%2==0) median = (nums[n/2]+nums[n/2-1])/2;
        else median=nums[n/2];
        
        sum=0;
        for(int num:nums) sum+=abs(num-median);
        return sum;
        
        
        // Approach 1: Gives TLE
        
        // long long int min,max,ans,sum;
        // min=*min_element(nums.begin(),nums.end());
        // max=*max_element(nums.begin(),nums.end());
        // ans=INT_MAX;
        // for(int i=min;i<=max;i++)
        // {
        //     sum=0;
        //     for(int num : nums)
        //     {
        //         sum+=abs(num-i);
        //     }
        //     ans=std::min(ans,sum);
        // }
        // return ans;
    }
};