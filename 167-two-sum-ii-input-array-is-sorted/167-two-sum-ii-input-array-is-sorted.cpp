class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int sum;
        for(int i=0,j=numbers.size()-1;i<j;)
        {
            sum=numbers[i]+numbers[j];
            if(sum==target)
            {
                numbers.clear();
                numbers.push_back(i+1);
                numbers.push_back(j+1);
                return numbers;
            }
            else if(sum<target) i++;
            else j--;
        }
        return numbers;
    }
};