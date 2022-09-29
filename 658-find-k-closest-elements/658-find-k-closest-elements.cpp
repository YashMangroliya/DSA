class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        int i,count,leftValue,rightValue,left,right;
        vector<int> ans;
        i=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        cout<<i<<endl;
        if(i==0)
        {
            arr.resize(k);
            return arr;
        }
        left=i-1;
        right=i;
        count=0;
        while(count<k && left>=0 && right<n)
        {
            leftValue=x-arr[left];
            rightValue=arr[right]-x;
            if(leftValue <= rightValue)
            {
                ans.push_back(arr[left]);
                left--;
            }
            else if(rightValue < leftValue)
            {
                ans.push_back(arr[right]);
                right++;
            }
            count++;
        }
        if(count<k)
        {
            if(left<0)
            {
                while(count<k) 
                {
                    ans.push_back(arr[right++]);
                    count++;
                }
            }
            if(right==n)
            {
                while(count<k)
                {
                    ans.push_back(arr[left--]);
                    count++;
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};