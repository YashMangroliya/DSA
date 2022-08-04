class Solution {
public:
    int mirrorReflection(int p, int q) {
        bool flag=true; // true for right-side, false for left-side
        int d=0;
        while(1)
        {
            d = d+q;
            if(d%p==0)
            {
                if(flag)
                {
                    return ((d/p)%2 == 1);
                }
                else
                {
                    return 2;
                }
            }
            flag=!flag;
        }
    }
};