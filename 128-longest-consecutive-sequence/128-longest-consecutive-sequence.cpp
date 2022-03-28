class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int i,num;
        int count=0,maxCount=0;
        for(int num : nums)
        {
            s.insert(num);
        }
        for(i=0;i<nums.size();i++)
        {
            if(s.count(nums[i]-1)==0)
            {
                num=nums[i]+1;
                count=0;
                while(1)
                {
                    count++;
                    if(s.count(num)==0) break;
                    num=num+1;
                }
                if(count>maxCount) maxCount=count;
            }
        }
        return maxCount;
    }
};