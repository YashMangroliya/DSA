class Solution {
public:
    bool isValid(string s) {
        int i=0,j;
        int size=s.length();
        int limit=size/2+2;
        char arr[size];
        for(char c:s)
        {
            if(c=='(')
            {
                arr[i]=c;
                i++;
                if(i>=limit) return false;
            }else if(c==')')
            {
                i--;
                if(i<0) return false;
                if(arr[i]!='(') return false;
            }else if(c=='{')
            {
                arr[i]=c;
                i++;
                if(i>=limit) return false;
            }else if(c=='}')
            {
                i--;
                if(i<0) return false;
                if(arr[i]!='{') return false;
            }else if(c=='[')
            {
                arr[i]=c;
                i++;
                if(i>=limit) return false;
            }else if(c==']')
            {
                i--;
                if(i<0) return false;
                if(arr[i]!='[') return false;
            }
        }
        if(i!=0) return false;
        return true;
    }
};