/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr) return {};
        queue<TreeNode*> que;
        que.push(root);
        vector<vector<int>> ans;
        int levelSize;
        while(!que.empty())
        {
            levelSize=que.size();
            vector<int> currentLevel;
            for(int i=0;i<levelSize;i++)
            {
                if(que.front()->left) que.push(que.front()->left);
                if(que.front()->right) que.push(que.front()->right);
                currentLevel.push_back(que.front()->val);
                que.pop();
            }
            ans.push_back(currentLevel);
        }
        return ans;
    }
};