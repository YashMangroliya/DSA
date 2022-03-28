class Solution {
public:
    void sortColors(vector<int>& nums) {
        int m,l,h;
        m=0;
        l=0;
        h=nums.size()-1;
        while(m<=h)
        {
            if(nums[m]==0)
            {
                swap(nums[l],nums[m]);
                l++;
                m++;
            }
            else if(nums[m]==1) m++;
            else if(nums[m]==2)
            {
                swap(nums[m],nums[h]);
                h--;
            }
        }
    }
};