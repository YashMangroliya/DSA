class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m,n,row,column;
        m=matrix.size();
        n=matrix[0].size();
        row=0;
        column=n-1;
        while(row<m && column>=0)
        {
            if(matrix[row][column]==target) return true;
            if(matrix[row][column]>target) column--;
            else row++;
        }
        return false;
    }
};