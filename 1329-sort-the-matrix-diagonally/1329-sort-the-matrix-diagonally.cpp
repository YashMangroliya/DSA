class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int i,j,row,col,index;
        vector<int> nums;
        for(i=mat.size()-1;i>=0;i--)
        {
            row=i;
            col=0;
            nums.clear();
            while(row<mat.size() && col<mat[0].size())
            {
                nums.push_back(mat[row][col]);
                row++;
                col++;
            }
            sort(nums.begin(),nums.end());
            
            row=i;
            col=0;
            index=0;
            while(row<mat.size() && col<mat[0].size())
            {
                mat[row][col]=nums[index];
                row++;
                col++;
                index++;
            }
        }
        
        for(j=1;j<mat[0].size();j++)
        {
            row=0;
            col=j;
            nums.clear();
            while(row<mat.size() && col<mat[0].size())
            {
                nums.push_back(mat[row][col]);
                row++;
                col++;
            }
            sort(nums.begin(),nums.end());
            
            row=0;
            col=j;
            index=0;
            while(row<mat.size() && col<mat[0].size())
            {
                mat[row][col]=nums[index];
                row++;
                col++;
                index++;
            }
        }
        return mat;
    }
};