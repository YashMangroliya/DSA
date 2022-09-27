class Solution {
public:
    string pushDominoes(string dominoes) {
        string original,current;
        original=dominoes;
        current=dominoes;
        int change=1;
        while(change>0)
        {
            cout<<change<<endl;
            change=0;
            for(int i=0;i<dominoes.length();i++)
            {
                if(current[i]!='.') continue;
                if(i==0)
                {
                    if(original[1]=='L') 
                    {
                        current[0]='L';
                        change++;
                    }
                    continue;
                }
                if(i==dominoes.length()-1)
                {
                    if(original[i-1]=='R')
                    {
                        current[i]='R';
                        change++;
                    }
                    continue;
                }
                if(original[i-1]=='R' && original[i+1]=='L') continue;
                if(original[i-1]=='R')
                {
                    current[i]='R';
                    cout<<"Part 2"<<endl;
                    change++;
                    continue;
                }
                if(original[i+1]=='L') 
                {
                    current[i]='L';
                    cout<<"Part 3"<<endl;
                    change++;
                    continue;
                }
            }
            original=current;
        }
        return original;
    }
};