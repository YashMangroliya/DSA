class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> heap;
        int n=matrix.size();
        make_heap(heap.begin(),heap.end(),[](const int a,const int b){ return (a>b); });
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                heap.push_back(matrix[i][j]);
                push_heap(heap.begin(),heap.end(),[](const int a,const int b){ return (a>b); });
            }
        }
        int num;
        for(int i=0;i<k;i++)
        {
            pop_heap(heap.begin(),heap.end(),[](const int a,const int b){ return (a>b); });
            num=heap.back();
            heap.pop_back();
        }
        return num;
    }
};