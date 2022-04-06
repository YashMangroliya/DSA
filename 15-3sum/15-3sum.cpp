class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        
        // Method 1 TLE
        
        // vector<vector<int>> ans;
        // if(nums.size()<3) return ans;
        // sort(nums.begin(),nums.end());
        // int required=0,curr,sum;
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
        
        
        
        // Method 2 TLE
        
        // vector<vector<int>> ans;
        // if(nums.size()<3) return ans;
        // unordered_map<int,int> map;
        // set<vector<int>> ansSet;
        // int curr,required;
        // required=0;
        // for(int i: nums) map[i]++;
        // for(int i=0;i<nums.size()-1;i++)
        // {
        //     map[nums[i]]--;
        //     curr=required-nums[i];
        //     for(int j=i+1;j<nums.size();j++)
        //     {
        //         map[nums[j]]--;
        //         if(map[curr-nums[j]]>0)
        //         {
        //             vector<int> v{nums[i],nums[j],curr-nums[j]};
        //             sort(v.begin(),v.end());
        //             ansSet.insert(v);
        //         }
        //         map[nums[j]]++;
        //     }
        //     map[nums[i]]++;
        // }
        // for(auto v: ansSet) ans.push_back(v);
        // return ans;
        
        // Method 3 (method 1 with some changes)
        
        vector<vector<int>> ans;
        if(nums.size()<3) return ans;
        sort(nums.begin(),nums.end());
        int required=0,curr,sum,prev;
        for(int i=0;i<nums.size()-2;i++)
        {
            if(i!=0 && nums[i]==nums[i-1]) continue;
            curr=required-nums[i];
            for(int j=i+1,k=nums.size()-1;j<k;)
            {
                sum=nums[j]+nums[k];
                if(sum==curr)
                {
                    vector<int> v{nums[i],nums[j],nums[k]};
                    ans.push_back(v);
                    prev=nums[j];
                    while(j<nums.size() && nums[j]==prev) j++;
                    prev=nums[k];
                    while(k<nums.size() && nums[k]==prev) k--;
                }
                else if(sum<curr) j++;
                else k--;
            }
        }
        return ans;
        
    }
};