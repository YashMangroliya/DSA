class Solution {
public:
    int strStr(string haystack, string needle) {
        int needleLength=needle.length();
        if(needleLength==0) return 0;
        int i=0,j=0;
        char c;
        int haystackLength=haystack.length();
        for(j=0;j<haystackLength;j++)
        {
            c=haystack[j];
            if(c==needle[i])
            {
                i++;
                if(i==needleLength) return j-needleLength+1;
            }
            else
            {
                j=j-i;
                i=0;
            }
        }
        return -1;
    }
};