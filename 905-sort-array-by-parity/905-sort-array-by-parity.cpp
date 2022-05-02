class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int e=0,f=nums.size()-1;
        
        while(e<f)
        {
            while(e<nums.size() && nums[e]%2==0) e++;
            while(f>=0 && nums[f]%2!=0) f--;
            if(e<f)
            {
                swap(nums[e],nums[f]);
            }
        }
        return nums;
    }
};