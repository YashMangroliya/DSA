class Solution {
public:
    string breakPalindrome(string palindrome) {
        int i=0;
        int n=palindrome.length();
        for(int i=0;i<n/2;i++)
        {
            if(palindrome[i]!='a')
            {
                palindrome[i]='a';
                return palindrome;
            }
        }
        if(n>1)
        {
            palindrome[n-1]='b';
            return palindrome;
        }
        return "";
    }
};