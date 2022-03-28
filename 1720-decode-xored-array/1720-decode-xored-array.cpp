class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> resultVector;
        resultVector.push_back(first);
        for(int num:encoded)
        {
            resultVector.push_back(resultVector.back()^num);
        }
        return resultVector;
    }
};