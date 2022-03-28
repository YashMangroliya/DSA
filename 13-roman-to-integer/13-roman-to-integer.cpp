class Solution {
public:
    int romanToInt(string s) {
        map<char,int> map;
        map['I']=1;
        map['V']=5;
        map['X']=10;
        map['L']=50;
        map['C']=100;
        map['D']=500;
        map['M']=1000;
        string str="IVXLCDM";
        int num=0;
        num=map[s[0]];
        int sLength=s.length();
        string::iterator e,f;
        for(e=s.begin(),f=e+1;f!=s.end();e++,f++)
        {
            if(str.find(*e)>=str.find(*f))
            {
                num+=map[*f];
            }
            else
            {
                num+=map[*f];
                num-=(2*map[*e]);
            }
        }
        return num;
        
    }
};