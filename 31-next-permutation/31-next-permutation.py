class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        def reverse(start,nums):
            ind1 = start+1
            last = len(nums)-1
            while ind1 < last:
                nums[ind1],nums[last] = nums[last],nums[ind1]
                ind1+=1
                last-=1
                
                
        ind1 = 0
        for i in range(len(nums)-2,-2,-1):
            if nums[i] < nums[i+1]:
                ind1 = i
                break
                
        print(i)
                
                
        ind2 = 0
        for j in range(len(nums)-1,-1,-1):
            if nums[j] > nums[ind1]:
                ind2 = j
                break
                
        if i == -1:
            print("here")
            reverse(-1,nums)
            print(nums)
                
        else:
            nums[ind1],nums[ind2] = nums[ind2],nums[ind1]
            print(nums)
            if ind1+1 == len(nums)-1:
                pass
            else:
                reverse(ind1,nums)
