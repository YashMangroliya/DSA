class KthLargest {
private:
    int k;
    vector<int> heap={};
public:
    // Method 1 TLE
//     KthLargest(int k, vector<int>& nums) {
//         this->k=k;
//         this->nums=nums;
//         make_heap(nums.begin(),nums.end());
//     }
    
//     int add(int val) {
//         int num;
//         this->nums.push_back(val);
//         make_heap(nums.begin(),nums.end());
//         for(int i=0;i<k-1;i++)
//         {
//             pop_heap(nums.begin(),nums.end()-i);
//             // nums.pop_back();
//         }
//         num=nums.front();
//         make_heap(nums.begin(),nums.end());
//         return num;
//     }
    
    
    struct greater{
        bool operator()(const int& a,const int & b) const{
            return a>b;
        }
    };
    
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        make_heap(heap.begin(),heap.end(),greater());
        for(int i=0;i<nums.size();i++)
        {
            heap.push_back(nums[i]);
            push_heap(heap.begin(),heap.end(),greater());
            if(heap.size()>k)
            {
                pop_heap(heap.begin(),heap.end(),greater());
                heap.pop_back();
            }
        }
        
    }
    
    int add(int val) {
        heap.push_back(val);
        push_heap(heap.begin(),heap.end(),greater());
        if(heap.size()>this->k)
        {
            pop_heap(heap.begin(),heap.end(),greater());
            heap.pop_back();
        }
        return heap.front();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */