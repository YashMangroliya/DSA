class Solution {
public:
    string addBinary(string a, string b) {
        string::reverse_iterator itr1=a.rbegin();
        string::reverse_iterator itr2=b.rbegin();
        string::reverse_iterator end1=a.rend();
        string::reverse_iterator end2=b.rend();
        string result="";
        bool carry=false;
        while(itr1!=end1 && itr2!=end2)
        {
            if(*itr1=='0')
            {
                if(*itr2=='0')
                {
                    if(carry)
                    {
                        result="1"+result;
                        carry=false;
                    }
                    else result="0"+result;
                }
                else
                {
                    if(carry)
                    {
                        result="0"+result;
                    }
                    else result="1"+result;
                }
            }
            else
            {
                if(*itr2=='0')
                {
                    if(carry)
                    {
                        result="0"+result;
                    }
                    else result="1"+result;
                }
                else
                {
                    if(carry)
                    {
                        result="1"+result;
                    }
                    else 
                    {
                        result="0"+result;
                        carry=true;
                    }
                }
                
            }
            itr1++;
            itr2++;
        }
        while(itr1!=end1)
        {
            if(carry)
            {
                if(*itr1=='0')
                {
                    result="1"+result;
                    carry=false;
                }
                else result="0"+result;
            }
            else
            {
                if(*itr1=='0') result="0"+result;
                else result="1"+result;
            }
            itr1++;
        }
        while(itr2!=end2)
        {
            if(carry)
            {
                if(*itr2=='0')
                {
                    result="1"+result;
                    carry=false;
                }
                else result="0"+result;
            }
            else
            {
                if(*itr2=='0') result="0"+result;
                else result="1"+result;
            }
            itr2++;
        }
        if(carry) result="1"+result;
        return result;
    }
};