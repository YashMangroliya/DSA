class Solution {
public:
    
    bool checkPallindrome(string s, int index)
    {
        string str="";
        int i,j;
        for(i=0;i<s.length();i++)
        {
            if(i!=index)
            {
                str+=s[i];
            }
        }
        for(i=0,j=str.length()-1;i<j;i++,j--)
        {
            if(str[i]!=str[j]) break;
        }
        return i>=j;
    }
    
    bool validPalindrome(string s) {
        bool ans=true;
        bool flag=false;
        for(int i=0,j=s.length()-1;i<j;i++,j--)
        {
            if(s[i]!=s[j])
            {
                if(flag) return false;
                if(s[i+1]==s[j] && checkPallindrome(s,i))
                {
                    flag=true;
                    i++;
                }
                else if(s[i]==s[j-1] && checkPallindrome(s,j))
                {
                    flag=true;
                    j--;
                }
                else return false;
            }
        }
        return true;
    }
};