class Solution {
public:
    
    vector<int> heap;
    unordered_map<int,int> m;
    vector<int> getTopK(int k)
    {
        vector<int> ans;
        int ri,ci,swi,g,lci,rci;
        while(k>0)
        {
            ans.push_back(heap[0]);
            swap(heap[0],heap[heap.size()-1]);
            heap.pop_back();
            ri=0;
            while(1)
            {
                lci=ri*2+1;
                rci=lci+1;
                if(lci>=this->heap.size()) break;
                if(rci>=this->heap.size()) swi=lci;
                else
                {
                    if(m[heap[lci]] > m[heap[rci]] ) swi=lci;
                    else swi=rci;
                }

                if(m[heap[swi]] > m[heap[ri]])
                {
                    swap(heap[ri],heap[swi]);
                    ri=swi;    
                }
                else break;
            }
            k--;
        }
        return ans;
    }
    
    void createHeap()
    {
        int ri,ci,g;
        for(int i=0;i<heap.size();i++)
        {
            ci=i;
            while(ci>0)
            {
                ri=(ci-1)/2;
                if(m[heap[ci]] > m[heap[ri]])
                {
                    g=heap[ci];
                    heap[ci]=heap[ri];
                    heap[ri]=g;

                    ci=ri;
                }
                else break;
            }
        }
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        for(int num : nums)
        {
            m[num]++;
            if(m[num]==1) heap.push_back(num);
        }
        createHeap();
        vector<int> ans = getTopK(k);
        return ans;
    }
};