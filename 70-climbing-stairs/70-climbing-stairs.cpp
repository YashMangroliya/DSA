class Solution {
public:
    int climbStairs(int n) {
        if(n<=3) return n;
        int x=2;
        int y=3;
        int t;
        for(int i=4;i<=n;i++)
        {
            t=y;
            y=y+x;
            x=t;
        }
        return y;
        
    }
};