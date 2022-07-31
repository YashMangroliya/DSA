class NumArray {
private:
    vector<int> nums;
    int sum;
public:
    NumArray(vector<int>& nums) {
        this->nums=nums;
        this->sum=accumulate(nums.begin(),nums.end(),0);
    }
    
    void update(int index, int val) {
        sum-=nums[index];
        sum+=val;
        this->nums[index]=val;
    }
    
    int sumRange(int left, int right) {
        int s;
        if(right-left<(nums.size()/2))
        {
            s=accumulate(nums.begin()+left,nums.begin()+right+1,0);
        }
        else
        {
            int l;
            if(left!=0) l=accumulate(nums.begin(),nums.begin()+left,0);
            else l=0;
            int r;
            if(right!=nums.size()-1)
            {
                r=accumulate(nums.begin()+right+1,nums.end(),0);
            }
            else r=0;
            s=this->sum-l-r;
        }
        return s;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */