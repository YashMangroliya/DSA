class Solution {
public:
    map<string,int> m;
    int rec(string s, string t, int i)
    {
        if(i>=t.length() || i>=s.length()) {
            int ans=t.length()-s.length();
            if(ans>=0) return ans;
            else return ans*-1;
        }
        if(m.find(s)!=m.end()) return m[s];
        int ans;
        if(s[i]==t[i])
        {
            ans = rec(s,t,i+1);
        }
        else
        {
            string ss;
            int count1,count2,count3;
            ss=s;
            ss.insert(ss.begin()+i,t[i]);
            count1 = rec(ss,t,i+1);
            
            ss=s;
            ss.erase(ss.begin()+i);
            count2 = rec(ss,t,i);
            
            ss=s;
            ss[i]=t[i];
            count3 = rec(ss,t,i+1);
            ans = min({count1,count2,count3})+1;
        }
        m[s]=ans;
        return ans;
    }

    int minDistance(string word1, string word2) {
        return rec(word1,word2,0);
    }
};