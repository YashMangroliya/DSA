class Solution {
public:
    int firstUniqChar(string s) {
        unordered_set<char> set1;
        for(int i=0;i<s.length();i++)
        {
            if(set1.count(s[i])==0 && s.find(s[i],i+1)==string::npos) return i;
            else set1.insert(s[i]);
        }
        return -1;
    }
};