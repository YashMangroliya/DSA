class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        while(s[i]==' ') i++;
        int sign=1;
        if(s[i]=='-') {
            sign=-1;
            i++;
        }
        else if(s[i]=='+') i++;
        int d;
        long ans=0;
        if(i<s.length() && (s[i]>=48 && s[i]<=57))
        {
            d=s[i]-48;
            ans= ans*10 +d;
            i++;
        }
        ans=ans*sign;
        while(i<s.length() && (s[i]>=48 && s[i]<=57) && ans<=INT_MAX && ans>=INT_MIN)
        {
            d=s[i]-48;
            if(sign==1) ans= ans*10 +d;
            else ans=ans*10-d;
            i++;
        }
        if(ans>INT_MAX) ans=INT_MAX;
        else if(ans<INT_MIN) ans=INT_MIN;
        return (int)ans;
    }
};