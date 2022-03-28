class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>::iterator itr;
        itr=find(nums.begin(),nums.end(),val);
        while(itr!=nums.end())
        {
            itr=find(nums.erase(itr),nums.end(),val);
        }
        return nums.size();
    }
};