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
    void inorder(TreeNode* root)
    {
        TreeNode* tmp, *prev , *first, *second;
        stack<TreeNode*> stk;
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
            
            if(first==nullptr && prev!=nullptr && prev->val > root->val)
            {
                first=prev;
            }
            if(first!=nullptr && prev->val > root->val)
            {
                second=root;
            }
                
            prev=root;
        }
        
        int g=first->val;
        first->val=second->val;
        second->val=g;
        return;
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        return;
    }
};