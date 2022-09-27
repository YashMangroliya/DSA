class Solution {
public:
    string pushDominoes(string dominoes) {
        string original,current;
        original=dominoes;
        current=dominoes;
        bool change=true;
        while(change)
        {
            change=false;
            for(int i=0;i<dominoes.length();i++)
            {
                if(current[i]!='.') continue;
                if(i==0)
                {
                    if(original[1]=='L') 
                    {
                        current[0]='L';
                        change=true;
                    }
                    continue;
                }
                if(i==dominoes.length()-1)
                {
                    if(original[i-1]=='R')
                    {
                        current[i]='R';
                        change=true;
                    }
                    continue;
                }
                if(original[i-1]=='R' && original[i+1]=='L') continue;
                if(original[i-1]=='R')
                {
                    current[i]='R';
                    change=true;
                    continue;
                }
                if(original[i+1]=='L') 
                {
                    current[i]='L';
                    change=true;
                    continue;
                }
            }
            original=current;
        }
        return original;
    }
};