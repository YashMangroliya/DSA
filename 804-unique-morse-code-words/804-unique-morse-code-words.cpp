class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> vec={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<string> set1;
        string key="";
        for(string s : words)
        {
            key="";
            for(int i=0;i<s.length();i++) key+=vec[s[i]-'a'];
            set1.insert(key);
        }
        return set1.size();
    }
};