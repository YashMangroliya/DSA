class Solution {
public:
    void rec(string num,int curr,int k,unordered_set<int>& ans,int n)
    {
        if(num.length()==n)
        {
            ans.insert(stoi(num));
            return;
        }
        string s;
        if(curr+k<10)
        {
            s=num+to_string(curr+k);
            rec(s,curr+k,k,ans,n);
        }
        if(curr-k>=0)
        {
            s=num+to_string(curr-k);
            rec(s,curr-k,k,ans,n);
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        unordered_set<int> s;
        vector<int> ans;
        for(int i=1;i<=9;i++)
        {
            rec(to_string(i),i,k,s,n);
        }
        for(int i : s)
        {
            ans.push_back(i);
        }
        return ans;
    }
};