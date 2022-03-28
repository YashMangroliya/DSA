class Solution {
public:
    int jump(vector<int>& arr) {
        int n=arr.size();
        int maxR,jumps,steps;
        maxR=arr[0];
        steps=arr[0];
        jumps=1;
        if(n==1) return 0;
        else if(arr[0]==0) return -1;
        else{
            for(int i=1;i<n;i++)
            {
                if(i==n-1)
                {
                    return jumps;
                }
                maxR=max(maxR,i+arr[i]);
                steps--;
                if(steps==0)
                {
                    jumps++;
                    if(i>=maxR)
                    {
                        return -1;
                    }
                    steps=maxR-i;
                }
            }
        }
        return false;

    }
};