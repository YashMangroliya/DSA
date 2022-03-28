class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        map<int,int> m;
        map<int,int>::iterator itr;
        int sum=0;
        for(int num:nums)
        {
            if(m.find(num)==m.end()) m[num]=1;
            else m[num]++;
        }
        for(itr=m.begin();itr!=m.end();itr++)
        {
            if(itr->second==1) sum+=itr->first;
        }
        return sum;
    }
};