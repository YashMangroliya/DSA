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
    TreeNode* top;
    void preOrder(TreeNode *curr)
    {
        if(curr==nullptr) return;
        TreeNode* right=curr->right, * left=curr->left;
        
        if(top!=nullptr)
        {
            top->right=curr;
            top->left=nullptr;
        }
        top=curr;
        preOrder(left);
        preOrder(right);
    }
    void flatten(TreeNode* root) {
        top=nullptr;
        preOrder(root);
    }
};