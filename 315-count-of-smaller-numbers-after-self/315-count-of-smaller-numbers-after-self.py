class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        vec=[]
        size=len(nums);
        ans=[]
        for i in range(size) : ans.append(0);
        i=size-1
        while i>=0 :
            itr=bisect_left(vec,nums[i]);
            ans[i]=itr
            vec.insert(itr,nums[i]);
            i-=1
        
        return ans;
        
        
        
#      vector<int> countSmaller(vector<int>& nums) {
#          vector<int> vec;
#          int size=nums.size();
#          vector<int> ans(size);
#          vector<int>::iterator itr;
         
#          for(int i=size-1;i>=0;i--)
#          {
#              itr=lower_bound(vec.begin(),vec.end(),nums[i]);
#              ans[i]=itr-vec.begin();
#              vec.insert(itr,nums[i]);
#          }
#          return ans;
#      }