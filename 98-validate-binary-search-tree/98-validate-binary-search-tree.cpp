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
    bool isValidBST(TreeNode* root) {
        // for validation we will just do a inorder traversal and check whether the order is in increaring form or not;
        stack<TreeNode*> stk;
        TreeNode* tmp,*prev=nullptr;
        while(root!=nullptr)
        {
            stk.push(root);
            root=root->left;
        }
        while(!stk.empty())
        {
            root=stk.top();
            stk.pop();
            tmp=root->right;
            while(tmp!=nullptr)
            {
                stk.push(tmp);
                tmp=tmp->left;
            }
            if(prev==nullptr)
            {
                prev=root;
            }
            else
            {
                if(prev->val >= root->val) return false;
                prev=root;
            }
        }
        return true;
    }
};