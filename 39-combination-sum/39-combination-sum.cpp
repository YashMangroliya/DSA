class Solution {
public:
    void find(int idx, int n, vector<int> &candidates, int target, vector<vector<int>> &ans, vector<int> &subset)
{
    if(idx == n) 
    {
        if(target == 0) 
            ans.push_back(subset);
        return;
    }
    if(candidates[idx] <= target)
    {
        subset.push_back(candidates[idx]);
        find(idx, n, candidates, target-candidates[idx], ans, subset);
        subset.pop_back();
    }
	find(idx+1, n, candidates, target, ans, subset);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> subset;
        int n = candidates.size();
        find(0, n, candidates, target, ans, subset);
        return ans;
    }
};