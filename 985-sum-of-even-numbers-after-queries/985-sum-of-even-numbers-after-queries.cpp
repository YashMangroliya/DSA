// TLE

// class Solution {
// public:
//     vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
//         vector<int> ans;
//         int sum;
//         for(vector<int>& v : queries)
//         {
//             nums[v[1]]= nums[v[1]]+v[0];
//             sum=0;
//             for(int n : nums) if(n%2==0) sum+=n;
//             ans.push_back(sum);
//         }
//         return ans;
//     }
// };


class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        vector<int> ans;
        int sum=0,prev,curr;
        for(int n : nums) if(n%2==0) sum+=n;
        for(vector<int>& v : queries)
        {
            prev=nums[v[1]];
            nums[v[1]]= nums[v[1]]+v[0];
            curr=nums[v[1]];
            
            if(prev%2==0)
            {
                sum-=prev;
            }
            if(curr%2==0) 
            {
                sum+=curr;
            }
            ans.push_back(sum);
        }
        return ans;
    }
};