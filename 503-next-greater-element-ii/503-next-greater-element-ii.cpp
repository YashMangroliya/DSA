class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // int greaterNum,i,j,num;
        // bool found=false;
        // vector<int> ans;
        // for(i=0;i<nums.size();i++)
        // {
        //     num=nums[i];
        //     found=false;
        //     for(j=i+1;j<nums.size();j++)
        //     {
        //         if(nums[j]>num) 
        //         {
        //             greaterNum=nums[j];
        //             found=true;
        //             break;
        //         }
        //     }
        //     if(!found)
        //     {
        //         for(j=0;j<i;j++)
        //         {
        //             if(nums[j]>num) 
        //             {
        //                 greaterNum=nums[j];
        //                 found=true;
        //                 break;
        //             }
        //         }
        //         if(!found) greaterNum=-1;
        //     }
        //     ans.push_back(greaterNum);
        // }
        // return ans;
        
        
        vector<int> ans;
        stack<int> s;
        int n=nums.size();
        for(int i=2*n-1;i>=0;i--)
        {
            while(s.empty()==false && s.top()<=nums[i%n])
            {
                s.pop();
            }
            
            if(i<n)
            {
                if(s.empty()==false) ans.insert(ans.begin(),s.top());
                else ans.insert(ans.begin(),-1);
            }
            s.push(nums[i%n]);
        }
        return ans;
    }
};