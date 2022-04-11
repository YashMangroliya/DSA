class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
//         Method 1
        
//         int m=grid.size();
//         int n=grid[0].size();
//         int lastNum;
//         int i,j;
        
//         while(k>0)
//         {
//             lastNum=grid[m-1][n-1];
//             for(i=m-1;i>=0;i--)
//             {
//                 for(j=n-1;j>=0;j--)
//                 {
//                     if(j!=0)
//                     {
//                         grid[i][j]=grid[i][j-1];
//                     }
//                     else if(i!=0)
//                     {
//                         grid[i][j]=grid[i-1][n-1];
//                     }
//                     else 
//                     {
//                         grid[0][0]=lastNum;
//                     }
//                 }
//             }
//             k--;
//         }
//         return grid;
    
    //     Method 2

        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> ans( n , vector<int> (m, 0));

        int i,j,oneDimensionalIndex,shiftedOneDimensionalIndex,shiftedRow,shiftedColumn;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                oneDimensionalIndex=m*i+j;
                shiftedOneDimensionalIndex=(oneDimensionalIndex+k) % (n*m);
                shiftedRow = shiftedOneDimensionalIndex / m;
                shiftedColumn = shiftedOneDimensionalIndex % m;
                ans[shiftedRow][shiftedColumn] = grid[i][j];
            }
        }
        return ans;
    }
};