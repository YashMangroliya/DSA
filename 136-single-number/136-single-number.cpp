class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int>::iterator itr,start,end;
        itr=nums.begin();
        start=nums.begin();
        end=nums.end();
        map<int,int> map1;
        for(int num:nums)
        {
            if(count(start,end,num)==1) return num;
            //num=*itr;
            //itr=nums.erase(itr);
            //if(find(nums.begin(),nums.end(),num)==end) return num;
        }
        return NULL;
    }
};