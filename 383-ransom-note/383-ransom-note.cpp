class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> ransomNoteMap,magazineMap;
        for(int i=0;i<ransomNote.length();i++)
        {
            ransomNoteMap[ransomNote[i]]++;
        }
        for(int i=0;i<magazine.length();i++)
        {
            magazineMap[magazine[i]]++;
        }
        
        for(auto entry : ransomNoteMap)
        {
            // cout<<entry.first<<endl;
            // cout<<entry.second<<endl;
            // cout<<ransomNoteMap[entry.first]<<endl;
            if(entry.second>magazineMap[entry.first]) return false;
        }
        return true;
    }
};