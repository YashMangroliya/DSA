class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1(nums1.begin(),nums1.end());
        set<int> s2(nums2.begin(),nums2.end());
        
        set<int>::iterator it;
        vector<int> num;
        int n1;
        for(it=s1.begin();it!=s1.end();it++)
        {
            n1=*it;
            if(s2.find(n1)!=s2.end()) num.push_back(n1);
        }
        return num;
    }
};