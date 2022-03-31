class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // int length,maxLength=0;
        // string ss;
        // char c;
        // for(int i=0;i<s.length();i++)
        // {
        //     ss="";
        //     length=0;
        //     for(int j=i;j<s.length();j++)
        //     {
        //         c=s.at(j);
        //         if(ss.find(c,0)!=string::npos)
        //         {
        //             break;
        //         }
        //         else{
        //             ss+=c;
        //             length++;
        //             maxLength=max(maxLength,length);
        //         }
        //     }
        // }
        // return maxLength;
        
        deque<char> dq;
        char c;
        int maxLength=0,length;
        for(int i=0;i<s.length();i++)
        {
            c=s.at(i);
            if(find(dq.begin(),dq.end(),c)!=dq.end())
            {
                while(dq.front()!=c) dq.pop_front();
                dq.pop_front();
            }
            dq.push_back(c);
            length=dq.size();
            maxLength=max(maxLength,length);
        }
        return maxLength;
    }
};