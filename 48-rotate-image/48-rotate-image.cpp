class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int i,j;
        int size=matrix.size();
        for(i=1;i<size;i++)
        {
            for(j=0;j<i;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        for(i=0;i<size;i++)
        {
            for(j=0;j<size/2;j++)
            {
                swap(matrix[i][j],matrix[i][size-1-j]);
            }
        }
    }
};