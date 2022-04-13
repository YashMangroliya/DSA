class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int c,r;
        r=c=n;
        vector<vector<int>> ans(n,vector<int>(n,0));
        int cs=0,ce=c-1,rs=0,re=r-1;
        int k,i,j;
        k=1;
        i=j=0;
        int element=1;
        while(cs<=ce && rs<=re)
        {
            while(j<=ce && j>=cs)
            {
                if(i<r && j<c && i>=0 && j>=0) ans[i][j]=element;
                element++;
                j+=k;
            }
            if(j>ce)
            {
                j=ce;
                i++;
            }
            else if(j<cs)
            {
                j=cs;
                i--;
            }
            
            while(i<=re && i>=rs)
            {
                if(i<r && j<c && i>=0 && j>=0) ans[i][j]=element;
                element++;
                i+=k;
            }
            if(i>re)
            {
                i=re;
                j--;
            }
            else if(i<rs)
            {
                i=rs;
                j++;
            }
            
            if(k==1)
            {
                rs++;
                ce--;
                k=-1;
            }
            else
            {
                re--;
                cs++;
                k=1;
            }
        }
        return ans;

    }
};