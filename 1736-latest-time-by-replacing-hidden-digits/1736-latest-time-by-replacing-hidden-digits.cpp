class Solution {
public:
    string maximumTime(string time) {
        if(time[4]=='?') time[4]='9';
        if(time[3]=='?') time[3]='5';
        if(time[1]=='?')
        {
            if(time[0]=='2' || time[0]=='?') time[1]='3';
            else time[1]='9';
        }
        if(time[0]=='?')
        {
            if((int)time[1]-48>3)
            {
                time[0]='1';
            }
            else time[0]='2';
        }
        
        return time;
    }
};