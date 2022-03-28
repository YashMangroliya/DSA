class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int highest=INT_MIN;
        int sum,j;
        int size=cardPoints.size();
            
        sum=0;
        for(j=0;j<k;j++)
        {
            sum+=cardPoints[j];
        }
        highest=sum;
        for(int i=1;i<=k;i++)
        {
            sum-=cardPoints[k-i];
            sum+=cardPoints[size-i];
            if(sum>highest) highest=sum;
        }
        return highest;
    }
};