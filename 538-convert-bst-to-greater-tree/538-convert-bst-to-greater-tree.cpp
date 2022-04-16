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
    int sum=0;
    void InorderTraversal(TreeNode* t)
    {
        if(t==nullptr) return;
        InorderTraversal(t->right);
        sum+=t->val;
        t->val=sum;
        InorderTraversal(t->left);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        InorderTraversal(root);
        return root;
    }
};