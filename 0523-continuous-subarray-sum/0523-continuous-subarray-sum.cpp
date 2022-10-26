class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(k==1) 
        {
            if(nums.size()>=2) return true;
            return false;
        }
        int sum=0,kk;
        unordered_map<int,int> map1;
        map1[0]=-1;
        int i=0;
        for(int n : nums)
        {
            sum+=n;
            kk=0;
            while(sum-kk >= 0)
            {
                if(map1.find(sum-kk)!=map1.end() && i-map1[sum-kk]>=2) return true;
                kk+=k;
            }
            
            if(map1.find(sum)==map1.end()) map1[sum]=i;;
            i++;
        }
        return false;
    }
};