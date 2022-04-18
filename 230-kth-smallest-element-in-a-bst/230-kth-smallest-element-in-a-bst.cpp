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
    int count=0,k,ans;
    bool inorder(TreeNode *root)
    {
        if(root==nullptr) return false;;
        if(inorder(root->left)) return true;
        count++;
        if(count==k)
        {
            ans=root->val;
            return true;
        }
        if(inorder(root->right)) return true;
        return false;
        
    }
    int kthSmallest(TreeNode* root, int k) {
        this->k=k;
        inorder(root);
        return ans;
    }
};