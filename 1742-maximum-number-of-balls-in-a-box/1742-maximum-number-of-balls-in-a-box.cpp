class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        int i,sum,num,value;
        map<int,int> m;
        for(i=lowLimit,value=1;i<=highLimit;i++)
        {
            for(num=i,sum=0;num>0;num/=10) sum+=(num%10);
            if(m.count(sum)==0) m[sum]=1;
            else if(++m[sum]>value) value=m[sum];
        }
        return value;
        
    }
};