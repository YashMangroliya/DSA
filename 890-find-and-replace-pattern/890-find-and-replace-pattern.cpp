class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        unordered_map<char,char> map1;
        vector<string> ans;
        bool flag=true;
        unordered_set<char> doneSet;
        for(string word : words)
        {
            flag=true;
            if(word.size()!=pattern.size()) continue;
            map1.clear();
            doneSet.clear();
            for(int i=0;i<pattern.length();i++)
            {
                if(map1.find(pattern[i])==map1.end())
                {
                    if(doneSet.count(word[i])>0) 
                    {
                        flag=false;
                        break;
                    }
                    map1[pattern[i]]=word[i];
                    doneSet.insert(word[i]);
                }
                else
                {
                    if(map1[pattern[i]]!=word[i]) 
                    {
                        flag=false;
                        break;
                    }
                }
            }
            if(flag) ans.push_back(word);
        }
        return ans;
    }
};