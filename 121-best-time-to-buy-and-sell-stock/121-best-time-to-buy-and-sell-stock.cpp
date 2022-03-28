class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min,max,gmax;
        min=INT_MAX;
        gmax=0;
        for(int price : prices)
        {
            if(price < min)
            {
                min=price;
                max=INT_MIN;
            }
            else if(price > max)
            {
                max=price;
                gmax=std::max(gmax,max-min);
            }
        }
        return gmax;
    }
};












