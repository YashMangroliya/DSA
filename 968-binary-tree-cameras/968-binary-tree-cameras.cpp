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
    int count=0;
    
    int postOrder(TreeNode * root)
    {
        if(root==nullptr) return 0;
        int left=postOrder(root->left);
        int right=postOrder(root->right);
        if(left==-1 || right==-1)
        {
            count++;
            return 1;
        }
        else if(left==1 || right==1)
        {
            return 0;
        }
        else {
            return -1;
        }
    }
    
    int minCameraCover(TreeNode* root) {
        int val=postOrder(root);
        if(val==-1) count++;
        return count;
    }
};