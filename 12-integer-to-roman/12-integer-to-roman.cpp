class Solution {
public:
    string intToRoman(int num) {
        string ans="";
        int n,i;
        if(num>=1000)
        {
            n=num/1000;
            for(i=0;i<n;i++) ans+="M";
            num=num%1000;
        }
        if(num>=500)
        {
            if(num/100==9)
            {
                ans+="CM";
                num=num%900;
            }
            else
            {
                ans+="D";
                num=num%500;
            }
        }
        if(num>=100)
        {
            n=num/100;
            if(n==4) ans+="CD";
            else for(i=0;i<n;i++) ans+="C";
            num=num%100;
        }
        if(num>=50)
        {
            if(num/10==9)
            {
                ans+="XC";
                num=num%90;
            }
            else 
            {
                ans+="L";
                num=num%50;
            }
        }
        if(num>=10)
        {
            n=num/10;
            if(n==4) ans+="XL";
            else for(i=0;i<n;i++) ans+="X";
            num=num%10;
        }
        if(num>=5)
        {
            if(num==9)
            {
                ans+="IX";
                num%=9;
            }
            else
            {
                ans+="V";
                num=num%5;
            }
        }
        if(num>=1)
        {
            if(num==4)
            {
                ans+="IV";
                num%=4;
            }
            else 
            {
                n=num/1;
                for(i=0;i<n;i++) ans+="I";
                num=num%1;
            }
        }
        return ans;
    }
};