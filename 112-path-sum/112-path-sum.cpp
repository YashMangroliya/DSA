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
    bool _hasPathSum(TreeNode *node,int sum,int targetSum){
        if(node->left==nullptr && node->right==nullptr)
        {
            return sum+node->val==targetSum;
        }
        if(node->left==nullptr) return _hasPathSum(node->right,sum+node->val,targetSum);
        if(node->right==nullptr) return _hasPathSum(node->left,sum+node->val,targetSum);
        return _hasPathSum(node->left,sum+node->val,targetSum) || _hasPathSum(node->right,sum+node->val,targetSum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==nullptr) return false;
        return _hasPathSum(root,0,targetSum);
    }
};