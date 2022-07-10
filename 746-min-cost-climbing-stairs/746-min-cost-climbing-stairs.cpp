class Solution {
public:
    int dp[1004];
    int rec(vector<int>& cost,int index)
    {
        if(dp[index]!=-1) return dp[index];
        if(index==cost.size()) return 0;
        int cost1=rec(cost,index+1);
        if(index+1==cost.size()) return cost1+cost[index];
        int cost2=rec(cost,index+2);
        dp[index]=min(cost1,cost2)+cost[index];
        return dp[index];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,1000*sizeof(dp[0]));
        return min(rec(cost,0),rec(cost,1));
    }
};