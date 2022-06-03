class NumMatrix {
private:
    vector<vector<int>> matrix1,matrix2;
public:
    
    NumMatrix(vector<vector<int>>& matrix) {
        this->matrix1=matrix;
        this->matrix2=matrix;
        int sum;
        
        for(int i=0;i<matrix1.size();i++)
        {
            sum=0;
            for(int j=0;j<matrix1[0].size();j++)
            {
                sum+=matrix1[i][j];
                matrix2[i][j]=sum;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum=0;
        for(int i=row1;i<=row2;i++)
        {
            if(col1!=0) sum += matrix2[i][col2] - matrix2[i][col1-1];
            else sum+= matrix2[i][col2];
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */