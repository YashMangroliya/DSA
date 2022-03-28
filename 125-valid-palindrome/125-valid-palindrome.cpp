/*
class Solution {
public:
    bool isPalindrome(string s) {
        string str="";
        int e,len,f;
        len=s.length();
        char c;
        for(e=0;e<len;e++)
        {
            
            c=s[e];
            if((c>=65 && c<=90) || (c>=97 && c<=122) || (c>=48 && c<=57)) str.push_back(c);
        }
        cout<<str<<endl;
        len=str.length();
        f=len-1;
        for(e=0;e<=f;e++,f--)
        {
            if(str[e]>90) str[e]=str[e]-32;
            if(str[f]>90) str[f]=str[f]-32;
            if(str[e]!=str[f]) return false;
        }
        return true;
    }
};
*/
class Solution {
public:
    bool isPalindrome(string s) {
        string str="";
        int e,len,f;
        len=s.length();
        f=len-1;
        char c1,c2;
        for(e=0;e<=f;e++,f--)
        {
            c1=s[e];
            c2=s[f];
            while(!(c1>=65 && c1<=90) && !(c1>=97 && c1<=122) && !(c1>=48 && c1<=57))
                  {
                      e++;
                      if(e>=len) return true;
                      c1=s[e];
                  }
            while(!(c2>=65 && c2<=90) && !(c2>=97 && c2<=122) && !(c2>=48 && c2<=57))
                {
                    f--;
                    if(f<0) return true;
                    c2=s[f];
                }
            if(c1>90) c1=c1-32;
            if(c2>90) c2=c2-32;
            if(c1!=c2) return false;
        }
        return true;
    }
};