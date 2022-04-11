class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        int lastNum;
        int i,j;
        while(k>0)
        {
            lastNum=grid[m-1][n-1];
            for(i=m-1;i>=0;i--)
            {
                for(j=n-1;j>=0;j--)
                {
                    if(j!=0)
                    {
                        grid[i][j]=grid[i][j-1];
                    }
                    else if(i!=0)
                    {
                        grid[i][j]=grid[i-1][n-1];
                    }
                    else 
                    {
                        grid[0][0]=lastNum;
                    }
                }
            }
            k--;
        }
        return grid;
    }
};