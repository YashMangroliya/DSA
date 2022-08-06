class Solution {
public:
    int poorPigs(int buckets, int poisonTime, int totalTime) {
//         int y = (Test/Die) + 1;
//         int z = y;
//         int count = 1;
//         if(buck==1){
//             return 0;
//         }

//         while(y<buck){

//             y = y * z;
//             count++;

//         }
//         return count;
        
        return ceil(log(buckets) / log(totalTime / poisonTime + 1));
    }
};