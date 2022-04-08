class Solution {
public:
    vector<string> ans;
    map<int,string> m;
    
    void combinations(string digits,int index,string str)
    {
        string s=m[digits[index]-48];
        if(index==digits.length()-1)
        {
            for(int i=0;i<s.length();i++)
            {
                string ss=str+s[i];
                ans.push_back(ss);
            }    
        }
        else
        {
            for(int i=0;i<s.length();i++)
            {
                string ss=str+s[i];
                combinations(digits,index+1,ss);
            }
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
        m.insert(make_pair(2,"abc"));
        m.insert({3,"def"});
        m[4]="ghi";
        m[5]="jkl";
        m[6]="mno";
        m[7]="pqrs";
        m[8]="tuv";
        m[9]="wxyz";
        combinations(digits,0,"");
        return ans;
    }
};