class Solution {
public:
    int threeSumMulti(vector<int>& nums, int target) {
        if(nums.size()<3) return 0;
        sort(nums.begin(),nums.end());
        int required=target,curr,sum;
        long count=0;        
        // Method 1 TLE
        
                
        for(int i=0;i<nums.size()-1;i++)
        {
            curr=required-nums[i];
            unordered_map<int,int> m;
            for(int j=i+1;j<nums.size();j++)
            {
                count+=m[curr-nums[j]];
                // if(s.find(curr-nums[j])!=s.end())
                // {
                //     count++;
                // }
                m[nums[j]]++;
            }
        }
        int ans=count%(1000000007);
        return ans;

    }
};