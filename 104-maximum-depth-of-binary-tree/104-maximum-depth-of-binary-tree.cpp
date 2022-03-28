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
    int maxDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        return maximumDepth(root,1);
    }
    int maximumDepth(TreeNode* root,int depth)
    {
        int depthLeft=0,depthRight=0;
        if(root->left)depthLeft=maximumDepth(root->left,depth+1);
        if(root->right)depthRight=maximumDepth(root->right,depth+1);
        if(!depthLeft && !depthRight) return depth;
        return max(depthLeft,depthRight);

    }
};