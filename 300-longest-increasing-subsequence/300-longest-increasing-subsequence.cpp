class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int i=0,lb,ub,mid;
        vector<int> v;
        v.push_back(nums[0]);
        
        for(i=1;i<nums.size();i++)
        {
            if(nums[i]>v.back())
            {
                v.push_back(nums[i]);
            }
            else if(nums[i]<v.front())
            {
                v[0]=nums[i];
            }
            else
            {
//                binary search for number equal to or just greater has been done in this   
                //  else block

                lb=0;
                ub=v.size()-1;
                while(1)
                {
                    mid=(lb+ub)/2;
                    if(v[mid]==nums[i]) break;
                    else
                    {
                        if((mid-1)>=0 && v[mid]>nums[i] && v[mid-1]<nums[i])
                        {
                            v[mid]=nums[i];
                            break;
                        }
                        else
                        {
                            if(v[mid]>nums[i])
                            {
                                ub=mid-1;
                            }
                            else{
                                lb=mid+1;
                            }
                        }
                    }
                }
            }
        }
        return v.size();
    }
};