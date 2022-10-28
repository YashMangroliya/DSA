class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map1;
        string ss;
        for(string s : strs)
        {
            ss=s;
            sort(ss.begin(),ss.end());
            map1[ss].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto entry : map1)
        {
            ans.push_back(entry.second);
        }
        return ans;
    }
};