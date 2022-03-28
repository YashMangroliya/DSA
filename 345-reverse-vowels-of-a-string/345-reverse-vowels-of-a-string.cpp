class Solution {
public:

    bool isVowel(char c)
    {
        if( c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U') return true;
        return false;
    }
    string reverseVowels(string s) {
        int i,j,size;
        char c;
        size=s.size();
        i=0;
        j=size-1;
        bool iFound,jFound;
        while(i<j)
        {
            while(i<j && isVowel(s[i])==false)
            {
                i++;
            }
            while(j>i && isVowel(s[j])==false)
            {
                j--;
            }
            swap(s[i],s[j]);
            i++;
            j--;
        }
        return s;
    }
};