class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int num,ii,index;
        for(int i=0;i<nums1.size();i++)
        {
            num=nums1[i];
            ii=-1;
            index=find(nums2.begin(),nums2.end(),num) - nums2.begin();
            for(int j=index+1;j<nums2.size();j++)
            {
                if(nums2[j]>num)
                {
                    ii=nums2[j];
                    break;
                }
            }
            ans.push_back(ii);
        }
        return ans;
    }
};