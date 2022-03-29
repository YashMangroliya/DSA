class Solution {
public:
    int trap(vector<int>& arr) {
        int n=arr.size();
        int total=0;
        int l,r,rmax,lmax;
        lmax=arr[0];
        rmax=arr[n-1];
        for(l=0,r=n-1;l<=r;)
        {
            if(arr[l]<=arr[r])
            {
                if(arr[l]>lmax) lmax=arr[l];
                else total=total+(lmax-arr[l]);
                l++;
            }
            else
            {
                if(arr[r]>rmax) rmax=arr[r];
                else total=total+(rmax-arr[r]);
                r--;
            }
        }
        return total;
    }
};