class Solution {
public:
   void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)    {
        if(m==0)
        {
            nums1=nums2;
            return;
        }
        int i,j,size;
        size=nums1.size();
        for(i=0,j=0;i<size && j<n;)
        {
            if(nums1[i]>=nums2[j])
            {
                nums1.insert(nums1.begin()+i,nums2[j]);
                i++;
                j++;
            }
            else {
                i++;
            }
        }
        nums1.resize(size);
        if(j<n)
        {
            // m+j is the number of numbers present inside nums1 (excluding 0s)
            for(i=m+j;i<size && j<n;i++,j++)
            {
                nums1[i]=nums2[j];
            }
        }
        
        
        
        
        
        
//         vector<int>::iterator itr1,itr2,end2,itr3;
//         int size=nums1.size();
//         nums1.resize(m+n);
//         itr1=nums1.begin();
//         itr2=nums2.begin();
//         end2=nums2.end();
//         int i=0;
//         itr3=nums1.end()-1;
//         for(i=0;*itr3==0;i++)
//         {
//             itr3--;
//         }
//         int k=size-i;
//         while(itr2!=end2 && k>0)
//         {
//             if(*itr1>*itr2)
//             {
//                 itr1=nums1.insert(itr1,*itr2);
//                 nums1.resize(n+m);
//                 itr2++;
//             }
//             else k--;
//             itr1++;
//         }
        
//         while(itr2!=end2 )
//         {
//             itr1=nums1.insert(itr1,*itr2);
//             itr2++;
//             itr1++;
//         }
//         nums1.resize(size);
    }
};