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
    
    # This code gives TLE in c++, this is because this bisect_left is more optimized than left_bound
    # Although this question is the Recursion count question but asked in different way, we can solve this using mergeSort method also
        
        
  