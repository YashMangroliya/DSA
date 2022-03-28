class Solution {
public:
    void reverseString(vector<char>& s) {
        int size=s.size();
        int i,j,g;
        i=0;
        j=size-1;
        while(i<j)
        {
            g=s[i];
            s[i]=s[j];
            s[j]=g;
            i++;
            j--;
        }
    }
};