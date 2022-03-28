class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int maxLen=0;
        int num=0;
        int minNum;
        for(vector<int> rectangle:rectangles)
        {
            minNum=min(rectangle[0],rectangle[1]);
            if(minNum==maxLen) num++;
            else if(minNum>maxLen)
            {
                maxLen=minNum;
                num=1;
            }
        }
        return num;
    }
};