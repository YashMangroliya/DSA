class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        long long int mini=INT_MAX;
        long long int maxa=INT_MIN;
        int minIndex,maxIndex;
        long long int size;
        size=nums.size();
        int count=0;
        for(int i=0;i<size;i++)
        {
            if(nums[i]<mini) 
            {
                minIndex=i;
                mini=nums[i];
            }
            if(nums[i]>maxa) 
            {
                maxIndex=i;
                maxa=nums[i];
            }
        }
        
        int ans1,ans2,ans3;
        ans1=min(minIndex,maxIndex)+1+size-max(minIndex,maxIndex);
        ans2=max(minIndex,maxIndex)+1;
        ans3=size-min(minIndex,maxIndex);
        return min(ans1,min(ans2,ans3));
        
        
        
//         int lastIndex=size-1;
//         if(maxIndex<minIndex)
//         {
//             if((maxIndex+1)<(size-minIndex))
//             {
//                 count+=(maxIndex+1);
//                 if(minIndex-maxIndex < size-minIndex) return count+minIndex-maxIndex;
//                 else return count+(size-minIndex);
//             }
//             else
//             {
//                 count+=(size-minIndex);
//                 if(maxIndex+1<(minIndex-maxIndex)) return count+maxIndex+1;
//                 else return count+minIndex-maxIndex;
//             }
//         }
//         else
//         {
//             if((minIndex+1)<(size-maxIndex))
//             {
//                 count+=(minIndex+1);
//                 if(maxIndex-minIndex < size-maxIndex) return count+maxIndex-minIndex;
//                 else return count+(size-maxIndex);
//             }
//             else
//             {
//                 count+=(size-maxIndex);
//                 if(minIndex+1<(maxIndex-minIndex)) return count+minIndex+1;
//                 else return count+maxIndex-minIndex;
//             }
//         }
//         return 0;
    }
};