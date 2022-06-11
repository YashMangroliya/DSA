class Solution {
public:
    // TLE  (Memoization) 
    // unordered_map<string,int> map1;
    // int func(vector<int> &nums,int x,int l,int r)
    // {
    //     if(nums.size()==0 || x<=0 || l>r) return -1;
    //     string key=to_string(l)+"*"+to_string(r)+"*"+to_string(x);
    //     if(map1.find(key)!=map1.end()) return map1[key];
    //     int front,back;
    //     front=nums[l];
    //     back=nums[r];
    //     if(front==x || back==x) return 1;
    //     if(front>x && back>x) return -1;
    //     int ans1=func(nums,x-front,l+1,r);
    //     int ans2=func(nums,x-back,l,r-1);
    //     int ans;
    //     if(ans1==-1 && ans2==-1) ans=-1;
    //     else if(ans1==-1) ans = ans2+1;
    //     else if(ans2==-1) ans = ans1+1;
    //     else ans = min(ans1,ans2)+1;
    //     map1[key]= ans;
    //     return ans;
    // }
    // int minOperations(vector<int>& nums, int x) {
    //     return func(nums,x,0,nums.size()-1);
    // }
    
    // Dynamic Programming
    
    int minOperations(vector<int>& nums, int x) {
        unordered_map<int,int> map1;
        int sum=0,ans=INT_MIN,ind;
        int numsSum = accumulate(nums.begin(),nums.end(),0);
        int perfectSubArraySum = numsSum-x;
        if(perfectSubArraySum==0) return nums.size();
        map1[0]=-1;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(map1.find(sum-perfectSubArraySum)!=map1.end())
            {
                ind=map1[sum-perfectSubArraySum];
                ans=max(ans,i-ind);
            }
            map1[sum]=i;
        }
        if(ans==INT_MIN) return -1;
        return nums.size()-ans;
    }
};