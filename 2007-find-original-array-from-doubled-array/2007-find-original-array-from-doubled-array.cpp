class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size()%2!=0) return {};
        unordered_map<int,int> map1;
        vector<int> ans;
        for(int n : changed)
        {
            map1[n]++;
        }
        sort(changed.begin(),changed.end());
        for(int n : changed)
        {
            if(map1[n]==0) continue;
            if(map1[n*2]==0) return {};
            ans.push_back(n);
            map1[n]--;
            map1[n*2]--;
        }
        return ans;
    }
};