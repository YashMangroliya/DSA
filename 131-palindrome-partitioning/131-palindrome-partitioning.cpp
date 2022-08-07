class Solution {
public:
    bool isPallindrome(string& s)
    {
        int i,j;
        for(i=0,j=s.length()-1;i<j;i++,j--)
        {
            if(s[i]!=s[j]) break;
        }
        return i>=j;
    }
    void findPartitions(string& s,int index,vector<string>& ds, vector<vector<string>>& ans)
    {
        if(index==s.length())
        {
            // cout<<"CAME HERE"<<endl;
            vector<string> v;
            v=ds;
            ans.push_back(v);
            return;
        }
        string ss;
        for(int i=index+1;i<=s.length();i++)
        {
            ss=s.substr(index,i-index);
            // cout<<ss<<" "<<isPallindrome(ss)<<endl;
            if(isPallindrome(ss))
            {
                ds.push_back(ss);
                findPartitions(s,i,ds,ans);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        findPartitions(s,0,ds,ans);
        return ans;
    }
};