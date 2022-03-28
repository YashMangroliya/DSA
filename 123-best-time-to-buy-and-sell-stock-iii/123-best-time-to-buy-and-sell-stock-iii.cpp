class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int i,lMin,rMax,profit;
        int size=prices.size();
        int left[size],right[size];
        lMin=prices[0];
        rMax=prices[size-1];
        left[0]=0;
        for(i=1;i<prices.size();i++)
        {
            left[i]=std::max(left[i-1],prices[i]-lMin);
            if(prices[i]<lMin) lMin=prices[i];
        }
        right[size-1]=0;
        for(i=size-2;i>=0;i--)
        {
            right[i]=std::max(right[i+1],rMax-prices[i]);
            if(prices[i]>rMax) rMax=prices[i];
        }
        profit=right[0];
        for(i=1;i<size;i++)
        {
            profit=std::max(profit,left[i-1]+right[i]);
        }
        return profit;
    }
};