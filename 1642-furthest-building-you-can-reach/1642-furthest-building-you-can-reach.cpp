#define ll long long int
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        // Giving wrong answer in some test cases
        vector<int> maximums;
        int prev=heights[0];
        int height, lowestAmongMaximums, i, diff;
        long long int sum;
        int s=ladders;
        
        struct greaters{ 
            bool operator()(const long& a,const long& b) const{ 
                return a>b; 
            } 
        }; 
        
        if(ladders==0)
        {
            sum=0;
            for(i=1;i<heights.size() && sum<=bricks; i++)
            {
                if(heights[i]>prev)
                {
                    sum+=(heights[i]-prev);
                    if(sum>bricks) break;
                }
                prev=heights[i];
            }
            return i-1;
        }
        
        for(i=1;i<heights.size();i++)
        {
            height=heights[i];
            if(height>prev)
            {
                diff=height-prev;
                if(ladders>0)
                {
                    maximums.push_back( diff );
                    ladders--;
                    if(ladders==0) make_heap(maximums.begin(),maximums.end(),greater());
                }
                else
                {
                    if(diff <= maximums.front())
                    {
                        if(diff > bricks) break;
                        else bricks-=diff;
                    }
                    else
                    {
                        lowestAmongMaximums=maximums.front();
                        pop_heap(maximums.begin(),maximums.end(),greater());
                        maximums.pop_back();
                        maximums.push_back(diff);
                        push_heap(maximums.begin(),maximums.end(),greater());
                        if(lowestAmongMaximums > bricks) break;
                        else bricks -= lowestAmongMaximums;
                    }
                }
            }
            prev=height;
        }
        return i-1;
        
        // Solution
        
        
//         priority_queue<ll, vector<ll> , greater<ll>> pq;
        
//         ll n=heights.size();
//         ll i,diff;
//         for(i=0;i<n-1;i++)
//         {
//             diff=heights[i+1]-heights[i];
//             if(diff>0)
//             {
//                 pq.push(diff);
//                 if(pq.size()<=ladders) continue;
//                 if(pq.top()>bricks) return i;
//                 else 
//                 {
//                     bricks -= pq.top();
//                     pq.pop();
//                 }
//             }
//         }
        //return n-1;
        
    }
};