class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char,int> mapS,mapT;
        for(int i=0;i<s.length();i++)
        {
            mapS[s[i]]++;
            mapT[t[i]]++;
        }
        for(auto entry : mapS)
        {
            if(mapT.find(entry.first)==mapT.end()) return false;
            if(mapT[entry.first]!=entry.second) return false;
        }
        return true;
        
    }
};