class Solution {
public:
    string longestPalindrome(string s) {
        int longest=0,k,l,si,ei;
        for(int i=0;i<s.length()-1;i++)
        {
            for(int j=s.length()-1;j>i;j--)
            {
                k=i;
                l=j;
                while( k<l && s[k]==s[l] )
                {
                    k++;
                    l--;
                }
                if(k>=l)
                {
                    if(j-i+1>longest)
                    {
                        longest=j-i+1;
                        si=i;
                        ei=j;
                    }
                    break;
                }
            }
        }
        cout<<si<<endl;
        cout<<ei<<endl;
        if(longest!=0) return s.substr(si,ei-si+1);
        return s.substr(0,1);
    }
};