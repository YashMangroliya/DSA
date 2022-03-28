class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int lmax,gmax,si,ei;
        lmax=nums[0];
        gmax=nums[0];
        int i=1;
        while(i<nums.size())
        {
            if(nums[i]>lmax+nums[i])
            {
                lmax=nums[i];
                si=i;
            }
            else{
                lmax=lmax+nums[i];
            }
            if(lmax>gmax){
                gmax=lmax;
                ei=i;
            }
            i++;
        }
        return gmax;
    }
};