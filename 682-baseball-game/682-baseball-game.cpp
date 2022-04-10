class Solution {
public:
    int calPoints(vector<string>& ops) {
        int score=0,last,secondLast;
        vector<int> ans;
        for(string s : ops)
        {
            if(s.compare("C")==0)
            {
                ans.pop_back();
            }
            else if(s.compare("D")==0)
            {
                ans.push_back(ans.back()*2);
            }
            else if(s.compare("+")==0)
            {
                last=ans.back();
                ans.pop_back();
                secondLast=ans.back();
                ans.push_back(last);
                ans.push_back(last+secondLast);
            }
            else 
            {
                ans.push_back(stoi(s));
            }
        }
        for(int i: ans) score+=i;
        return score;
    }
};