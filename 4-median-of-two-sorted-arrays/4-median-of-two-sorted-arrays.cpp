class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1=nums1.size();
        int size2=nums2.size();
        int i=0;
        int index1=0,index2=0,val,ii,medianIndex1,medianIndex2;
        double ans,m1,m2;
        if(size1==size2)
        {
            medianIndex1=size1-1;
            medianIndex2=medianIndex1+1;
        }
        else if((size1+size2)%2==0)
        {
            medianIndex1=(size1+size2)/2 - 1;
            medianIndex2=medianIndex1+1;
        }
        if(size1==size2 || (size1+size2)%2==0)
        {
            while(i<=medianIndex2)
            {
                if(index1>=nums1.size())
                {
                    val=nums2[index2];
                    index2++;
                }
                else if(index2>=nums2.size())
                {
                    val=nums1[index1];
                    index1++;
                }
                else if(nums1[index1]<nums2[index2])
                {
                    val=nums1[index1];
                    index1++;
                }
                else
                {
                    val=nums2[index2];
                    index2++;
                }
                if(i==(medianIndex1))
                {
                    m1=val;
                }
                if(i==medianIndex2)
                {
                    m2=val;
                }
                i++;
            }
            ans=(m1+m2)/2;
        }
        else
        {
            ii=(size1+size2)/2;
            while(i<=ii)
            {
                if(index1>=nums1.size())
                {
                    val=nums2[index2];
                    index2++;
                }
                else if(index2>=nums2.size())
                {
                    val=nums1[index1];
                    index1++;
                }
                else if(nums1[index1]<nums2[index2])
                {
                    val=nums1[index1];
                    index1++;
                }
                else
                {
                    val=nums2[index2];
                    index2++;
                }
                if(i==ii)
                {
                    ans=val;
                }
                i++;
            }
        }
        return ans;
    }
};