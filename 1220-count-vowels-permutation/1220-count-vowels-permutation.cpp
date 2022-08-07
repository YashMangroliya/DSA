class Solution {
public:
    int countVowelPermutation(int n) {
        unordered_map<char,vector<long long>> map1;
        map1['a'].push_back(1);
        map1['e'].push_back(1);
        map1['i'].push_back(1);
        map1['o'].push_back(1);
        map1['u'].push_back(1);
        
        for(int i=1;i<n;i++)
        {
            (map1['a']).push_back(map1['e'][i-1]+map1['i'][i-1]+map1['u'][i-1] %(1000000007) );
        (map1['e']).push_back(map1['a'][i-1]+map1['i'][i-1] %(1000000007));
        (map1['i']).push_back(map1['o'][i-1]+map1['e'][i-1] %(1000000007));
        (map1['o']).push_back(map1['i'][i-1] %(1000000007));
        (map1['u']).push_back(map1['o'][i-1]+map1['i'][i-1] %(1000000007));
 
        }
        
        return (map1['a'].back()+map1['e'].back()+map1['i'].back()+ map1['o'].back()+ map1['u'].back())%(1000000007);
    }
    
};