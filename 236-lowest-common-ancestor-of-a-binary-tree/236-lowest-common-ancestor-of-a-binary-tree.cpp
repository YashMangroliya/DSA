        
    
 /*     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *     int val;
 * Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left,*right;
 };*/


class Solution {
public:
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        if(root->val==p->val || root->val==q->val) return root;
        TreeNode *left,*right;
        left=lowestCommonAncestor(root->left,p,q);
        right=lowestCommonAncestor(root->right,p,q);
        if(left!=NULL && right!=NULL) return root;
        if(left==NULL && right==NULL) return NULL;
        if(left!=NULL) return left;
        return right;
    }
};