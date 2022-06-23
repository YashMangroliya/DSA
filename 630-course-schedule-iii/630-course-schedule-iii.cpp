    
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& cources) {
        vector<int> heap;
        make_heap(heap.begin(),heap.end());
        sort(cources.begin(),cources.end(),[](vector<int>& v1,vector<int>& v2){
            if(v1[1]==v2[1]) return v1[0]<v2[0];
            return v1[1]<v2[1];
        });
        int sum=0;
        for(vector<int> cource: cources)
        {
            if(cource[0]>cource[1]) continue;
            if(sum+cource[0]<=cource[1])
            {
                sum+=cource[0];
                heap.push_back(cource[0]);
                push_heap(heap.begin(),heap.end());
            }
            else
            {
                if(heap.front()>cource[0])
                {
                    sum-=heap.front();
                    sum+=cource[0];
                    pop_heap(heap.begin(),heap.end());
                    heap.pop_back();
                    heap.push_back(cource[0]);
                    push_heap(heap.begin(),heap.end());
                }
            }
        }
        return heap.size();
    }
};