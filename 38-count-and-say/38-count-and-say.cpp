class Solution {
public:
    string countAndSay(int n) {
        
        string s="1";
        string newStr;
        int count;
        char prevChar;
        while(n>1)
        {
            prevChar=s[0];
            count=1;
            newStr="";
            for(int i=1;i<s.length();i++)
            {
                if(s[i]==prevChar) count++;
                else 
                {
                    newStr+=(count+48);
                    newStr+=prevChar;
                    prevChar=s[i];
                    count=1;
                }
            }
            newStr+=(count+48);
            newStr+=prevChar;
            s=newStr;
            n--;
        }
        return s;
    }
};