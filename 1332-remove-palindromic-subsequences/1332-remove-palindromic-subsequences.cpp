class Solution {
public:
    int removePalindromeSub(string s) {
        // It's subsequences (I mistakenly assume it's substring lol). The maximum number of steps will be 2. First, remove all 'a'. Then, remove all 'b'.
        string rev=s;
        reverse(rev.begin(),rev.end());
        if(s==rev) return 1;
        return 2;
    }
};