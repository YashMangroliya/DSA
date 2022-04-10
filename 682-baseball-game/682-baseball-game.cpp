class Solution {
public:
    int calPoints(vector<string>& ops) {
        int score=0,last,secondLast;
        stack<int> ans;
        for(string s : ops)
        {
            if(s.compare("C")==0)
            {
                ans.pop();
            }
            else if(s.compare("D")==0)
            {
                ans.push(ans.top()*2);
            }
            else if(s.compare("+")==0)
            {
                last=ans.top();
                ans.pop();
                secondLast=ans.top();
                ans.push(last);
                ans.push(last+secondLast);
            }
            else 
            {
                ans.push(stoi(s));
            }
        }
        while(ans.empty()==false) 
        {
            score+=ans.top();
            ans.pop();
        }
        return score;
    }
};