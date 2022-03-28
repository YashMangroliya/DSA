class Solution {
public:
    int reverse(int x) {
        int digit,n;
        long l;
        if(x==-2147483648) return 0;
        if(x<0)
        {
            n=-x;
        }
        else n=x;
        while(n>0)
        {
            digit=n%10;
            n/=10;
            l=l*10+digit;
        }
        if((x<0 && l>2147483648) || x>0 && l>2147483647 ) return 0;
        if(x<0) return -(int)l;
        return (int)l;
    }
};