#User function Template for python3

class Solution:
    def sort012(self,arr,n):
        i= arr.index(0)
        j = arr.index(1) 
        k = arr.index(2)
        if j < k:
            i,j = j,j+1
        else:
            i,j = k,k+1
        for j in range(j,n):
            if arr[j]==0:
                arr[i],arr[j]= arr[j],arr[i]
                i+=1
        i = arr.index(2)
        #j = arr.index(2)
        #print(arr)
        #if i<j:
         #   i=j;
        
        for j in range(i+1,n):
            if arr[j]==1:
                arr[i],arr[j]= arr[j],arr[i]
                i+=1
#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t=int(input())
    for _ in range(t):
        n=int(input())
        arr=[int(x) for x in input().strip().split()]
        ob=Solution()
        ob.sort012(arr,n)
        for i in arr:
            print(i, end=' ')
        print()

# } Driver Code Ends