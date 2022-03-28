class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int c,r;
        r=matrix.size();
        c=matrix[0].size();
        vector<int> ans;
        int cs=0,ce=c-1,rs=0,re=r-1;
        int k,i,j;
        k=1;
        i=0;
        j=0;
        while(cs<=ce && rs<=re)
        {
            while(j<=ce && j>=cs)
            {
                // cout<<matrix[i][j]<<" ";
                if(i<r && j<c && i>=0 && j>=0) ans.push_back(matrix[i][j]);
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
                // cout<<matrix[i][j]<<" ";
                if(i<r && j<c && i>=0 && j>=0) ans.push_back(matrix[i][j]);
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