class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> heap;
        int n=matrix.size();
        make_heap(heap.begin(),heap.end());
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                heap.push_back(matrix[i][j]);
                push_heap(heap.begin(),heap.end());
                if(heap.size()>k)
                {
                    pop_heap(heap.begin(),heap.end());
                    heap.pop_back();
                }
            }
        }
        pop_heap(heap.begin(),heap.end());
        return heap.back();
    }
};