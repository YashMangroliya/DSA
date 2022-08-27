class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<string> vec;
        int num=1;
        string numString;
        for(int i=0;i<31;i++)
        {
            numString=to_string(num);
            sort(numString.begin(),numString.end());
            vec.push_back(numString);
            if(i!=30) num=num*2;
        }
        string str2=to_string(n);
        sort(str2.begin(),str2.end());
        for(string str1 : vec)
        {
            if(str1==str2) return true;
        }
        return false;
        
    }
};