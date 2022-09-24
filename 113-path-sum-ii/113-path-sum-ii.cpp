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
    void helper(TreeNode* root,int targetSum,int sum,vector<int>& vec,vector<vector<int>>& ans)
    {
        if(root->left==nullptr && root->right==nullptr && sum==targetSum) ans.push_back(vec);
        if(root->left!=nullptr)
        {
            vec.push_back(root->left->val);
            sum+=root->left->val;
            helper(root->left,targetSum,sum,vec,ans);
            sum-=root->left->val;
            vec.pop_back();
        }
        if(root->right!=nullptr)
        {
            vec.push_back(root->right->val);
            sum+=root->right->val;
            helper(root->right,targetSum,sum,vec,ans);
            sum-=root->right->val;
            vec.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(root==nullptr) return ans;
        vector<int> vec;
        vec.push_back(root->val);
        helper(root,targetSum,root->val,vec,ans);
        return ans;
    }
};