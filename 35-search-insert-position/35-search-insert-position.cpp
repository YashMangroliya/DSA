class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int numsLength=nums.size();
        if(numsLength==0) return 0;
        int pos=0;
        for(int num:nums)
        {
            if(num>=target) break;
            pos++;
        }
        return pos;
    }
};