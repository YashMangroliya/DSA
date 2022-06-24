class Solution {
public:
    
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq;
        long sum=0,val,maximum;
        for(int i=0;i<target.size();i++)
        {
            pq.push(target[i]);
            sum+=target[i];
        }
        while(pq.top()!=1)
        {
            maximum=pq.top();
            pq.pop();
            sum=sum-maximum;
            if(sum<=0 || sum>=maximum) return false;
            val=maximum % sum;
            if(val!=0) pq.push(val);
            else pq.push(sum);
            sum+=val;
        }
        return true;
    }
};