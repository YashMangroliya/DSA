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
private:
    bool postOrder(TreeNode* node)
    {
        if(node==nullptr) return false;
        bool left=false,right=false;
        left=postOrder(node->left);
        right=postOrder(node->right);
        if(!left) node->left=nullptr;
        if(!right) node->right=nullptr;
        if(left || right || node->val==1) return true;
        return false;
        
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        bool flag = postOrder(root);
        if(flag) return root;
        return nullptr;
    }
};