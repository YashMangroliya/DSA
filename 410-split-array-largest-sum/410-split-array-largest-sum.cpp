class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int largest=-1,sum=0,i,low,high,mid,subArrayCount=0,ans=INT_MAX,s;
        for(i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(nums[i]>largest) largest=nums[i];
        }
        low=largest;
        high=sum;
        while(low<=high)
        {
            cout<<low<<endl;
            cout<<high<<endl;
            cout<<endl;
            mid=low+(high-low)/2;
            s=0;
            subArrayCount=0;
            for(i=0;i<nums.size() && subArrayCount<=m ;i++)
            {
                s+=nums[i];
                if(s>mid)
                {
                    s=nums[i];
                    subArrayCount++;
                }
            }
            subArrayCount++;
            if(subArrayCount<=m)
            {
                cout<<"Low: "<<low<<endl;
                cout<<"High: "<<high<<endl;
                ans=min(ans,mid);
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};