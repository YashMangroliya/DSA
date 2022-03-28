class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows,columns;
        int low,mid,high,midValue;
        rows=matrix.size();
        columns=matrix[0].size();
        low=0;
        high=rows*columns-1;
        while(low<=high)
        {
            mid=(high+low)/2;
            midValue=matrix[mid/columns][mid%columns];
            if(midValue==target) return true;
            if(midValue<target) low=mid+1;
            if(midValue>target) high=mid-1;
        }
        return false;
    }
};