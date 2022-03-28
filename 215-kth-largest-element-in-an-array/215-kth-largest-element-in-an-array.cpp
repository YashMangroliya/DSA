class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int arr[nums.size()];
        int ri,lci,rci,ci,li;
        // Creating max heap
        arr[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            arr[i]=nums[i];
            ci=i;
            while(ci>0)
            {
                ri=(ci-1)/2;
                if(arr[ri]<arr[ci]) swap(arr[ri],arr[ci]);
                else break;
                ci=ri;
            }
        }

        li=nums.size()-1;
        for(int i=0;i<(k-1);i++)
        {
            arr[0]=arr[li];
            li--;
            //adjusting heap
            ri=0;
            while(1)
            {
                lci=ri*2+1;
                rci=lci+1;
                if(lci>li) break;
                if(rci>li)
                {
                    if(arr[lci]>arr[ri])
                    {
                        swap(arr[lci],arr[ri]);
                    }
                    break;
                }
                if(arr[lci]>arr[rci])
                {
                    if(arr[ri]<arr[lci]){
                        swap(arr[ri],arr[lci]);
                        ri=lci;
                    }
                    else break;
                }
                else
                {
                    if(arr[ri]<arr[rci])
                    {
                        swap(arr[ri],arr[rci]);
                        ri=rci;
                    }
                    else break;
                }
            }
        }
        return arr[0];
    }
};