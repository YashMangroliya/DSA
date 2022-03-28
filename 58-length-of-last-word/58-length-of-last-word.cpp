class Solution {
public:
    int lengthOfLastWord(string s) {
        int pos=s.find_last_not_of(" ");
        s.resize(pos+1);
        pos=s.rfind(" ");
        int sLength=s.length();
        if(pos==-1) return sLength;
        return sLength-pos-1;
    }
};