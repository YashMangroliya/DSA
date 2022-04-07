class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
//         Method 1
        
//         int first,second,low,high,mid,diff;
//         sort(stones.begin(),stones.end());
//         while(stones.size()>1)
//         {
//             first=stones.back();
//             stones.pop_back();
//             second=stones.back();
//             stones.pop_back();
//             if(first!=second)
//             {
//                 diff=abs(first-second);
//                 // logic to find appropriate position for diff in stones vector
//                 low=0;
//                 high=stones.size()-1;
//                 while(low<high)
//                 {
//                     mid=(high+low)/2;
//                     if(stones[mid] <= diff) low=mid+1;
//                     else high=mid;
//                 }
//                 // low is the required position
//                 stones.insert(stones.begin()+low,diff);
//             }
//         }
//         if(stones.size()==0) return 0;
//         return stones[0];
        
        // Method 2
        
        int first,second,diff;
        make_heap(stones.begin(),stones.end());
        while(stones.size()>1)
        {
            first=stones.front();
            pop_heap(stones.begin(),stones.end());
            stones.pop_back();
            second=stones.front();
            pop_heap(stones.begin(),stones.end());
            stones.pop_back();
            diff=abs(first-second);
            if(diff!=0)
            {
                stones.push_back(diff);
                push_heap(stones.begin(),stones.end());
            }
        }
        if(stones.size()==0) return 0;
        return stones[0];
    }
};