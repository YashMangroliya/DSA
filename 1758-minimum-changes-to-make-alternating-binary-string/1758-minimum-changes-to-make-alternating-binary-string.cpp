class Solution {
public:
    int minOperations(string s) {
        string::iterator itr;
        int count1=0;
        int count2=0;
        char c='0';
        for(itr=s.begin();itr!=s.end();itr++)
        {
            if(*itr!=c) count1++;
            if(c=='0') c='1';
            else c='0';
        }
        c='1';
        for(itr=s.begin();itr!=s.end();itr++)
        {
            if(*itr!=c) count2++;
            if(c=='0') c='1';
            else c='0';
        }
        if(count1<count2) return count1;
        return count2;
    }
};