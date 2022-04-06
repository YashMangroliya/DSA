class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> ans;
        if(nums.size()<3) return ans;
        sort(nums.begin(),nums.end());
        int required=0,curr,sum;
        set<vector<int>> ansSet;
        // set<vector<int>> s;
        // for(int i=0;i<nums.size()-2;i++)
        // {
        //     curr=required-nums[i];
        //     for(int j=i+1,k=nums.size()-1;j<k;)
        //     {
        //         sum=nums[j]+nums[k];
        //         if(sum==curr)
        //         {
        //             vector<int> v{nums[i],nums[j],nums[k]};
        //             s.insert(v);
        //             j++;
        //             k--;
        //         }
        //         else if(sum<curr) j++;
        //         else k--;
        //     }
        // }
        // for(auto v : s) ans.push_back(v);
        // return ans;
        
        for(int i=0;i<nums.size()-1;i++)
        {
            if(i!=0 && nums[i]==nums[i-1]) continue;
            curr=required-nums[i];
            unordered_set<int> s;
            for(int j=i+1;j<nums.size();j++)
            {
                if(s.find(curr-nums[j])!=s.end())
                {
                    vector<int> v{nums[i],nums[j],curr-nums[j]};
                    ansSet.insert(v);
                }
                s.insert(nums[j]);
            }
        }
        for(auto v : ansSet) ans.push_back(v);
        return ans;
    }
};