class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int greaterNum,i,j,num;
        bool found=false;
        vector<int> ans;
        for(i=0;i<nums.size();i++)
        {
            num=nums[i];
            found=false;
            for(j=i+1;j<nums.size();j++)
            {
                if(nums[j]>num) 
                {
                    greaterNum=nums[j];
                    found=true;
                    break;
                }
            }
            if(!found)
            {
                for(j=0;j<i;j++)
                {
                    if(nums[j]>num) 
                    {
                        greaterNum=nums[j];
                        found=true;
                        break;
                    }
                }
                if(!found) greaterNum=-1;
            }
            ans.push_back(greaterNum);
        }
        return ans;
    }
};