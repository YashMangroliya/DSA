class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
//         TLE 
    //     deque<int> dq;
    //     int sum=0,gsum=0;
    //     for(int i : nums)
    //     {
    //         if(find(dq.begin(),dq.end(),i)!=dq.end())
    //         {
    //             while(dq.front()!=i)
    //             {
    //                 sum-=dq.front();
    //                 dq.pop_front();
    //             }
    //             dq.pop_front();
    //             dq.push_back(i);
    //         }
    //         else
    //         {
    //             dq.push_back(i);
    //             sum+=i;
    //             gsum=max(gsum,sum);
    //         }
    //     }
    //     return gsum;
    // }
        
        
        unordered_set<int> set1;
        int sum=0,gsum=0,i=0;
        for(int num : nums)
        {
            while(set1.count(num)>0)
            {
                set1.erase(nums[i]);
                sum-=nums[i];
                i++;
            }
            set1.insert(num);
            sum+=num;
           
            gsum=max(gsum,sum);
        }
        return gsum;
    }
};