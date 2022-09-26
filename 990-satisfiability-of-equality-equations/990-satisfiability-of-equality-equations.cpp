class Solution {
public:
    vector<char> parent;
    char rootFind(char c)
    {
        if(parent[c]==c)  return c;
        else  return rootFind(parent[c]);
    }
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26,0);
        for(int i=0;i<26;i++) parent[i]=i;
        int parA,parB;
        for(string s : equations)
        {
            if(s[1]=='=')
            {
                parA=rootFind(s[0]-'a');
                parB=rootFind(s[3]-'a');
                if(parA!=parB)
                {
                    parent[parB]=parA;
                }
            }
        }
        for(string s : equations)
        {
            if(s[1]=='!')
            {
                parA=rootFind(s[0]-'a');
                parB=rootFind(s[3]-'a');
                if(parA==parB) return false;
            }
        }
        return true;
    }
};