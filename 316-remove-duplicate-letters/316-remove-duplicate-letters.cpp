class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> lastIndex;
        char c;
        for(int i=s.length()-1;i>=0;i--)
        {
            c=s[i];
            if(lastIndex.find(c)==lastIndex.end())
            {
                lastIndex[c]=i;
            }
        }
        // for(auto entry : lastIndex) cout<<entry.first<<","<<entry.second<<endl;
        
        stack<char> stk;
        vector<bool> visited(26,false);
        
        int index=0;
        for(char c : s)
        {
            if(visited[(int)c-97])
            {
                index++;
                continue;
            }
            if(stk.empty())
            {
                stk.push(c);
                visited[(int)c-97]=true;
            }
            else
            {
                if( (int)stk.top() < (int)c || lastIndex[stk.top()]<=index) 
                {
                    stk.push(c);
                    visited[(int)c-97]=true;
                }
                else 
                {
                    while( stk.empty()==false && (int)stk.top() > (int)c && lastIndex[stk.top()]>index)
                    {
                        visited[(int)stk.top()-97]=false;
                        stk.pop();
                    }
                    stk.push(c);
                    visited[(int)c-97]=true;
                }
            }
            index++;
        }
        string ans="";
        while(stk.empty()==false)
        {
            ans=stk.top()+ans;
            stk.pop();
        }
        return ans;
    }
};