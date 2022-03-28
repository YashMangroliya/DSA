class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>::iterator itr=(unique(nums.begin(),nums.end()));
        nums.resize(distance(nums.begin(),itr));
        return nums.size();
    }
};