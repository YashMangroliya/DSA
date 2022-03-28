class Solution {
public:
    bool isPalindrome(int x) {
        string s=std::to_string(x);
        string:: iterator start,end;
        start=s.begin();
        end=s.end()-1;
        for(;start<end;start++,end--)
        {
            if(*start!=*end) break;
        }
        if(start<end) return false;
        return true;

    }
};