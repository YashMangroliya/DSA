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
    bool isSymmetric(TreeNode* root) {
        TreeNode *p,*q;
        p=root->left;
        q=root->right;
        if(!p && !q) return true;
        if(!p && q) return false;
        if(p && !q) return false;
        stack<TreeNode*> stk1,stk2;
        stk1.push(p);
        stk2.push(q);
        bool same=true,lFlag,rFlag;
        TreeNode *l,*r;
        while(stk1.size() && stk2.size())
        {
            l=stk1.top();
            stk1.pop();
            r=stk2.top();
            stk2.pop();
            if(l->val!=r->val)
            {
                same=false;
                break;
            }
            lFlag=l->left==nullptr;
            rFlag=r->right==nullptr;
            if(lFlag!=rFlag)
            {
                same=false;
                break;
            }
            lFlag=l->right==nullptr;
            rFlag=r->left==nullptr;
            if(lFlag!=rFlag)
            {
                same=false;
                break;
            }
            if(l->right)stk1.push(l->right);
            if(l->left)stk1.push(l->left);
            if(r->left)stk2.push(r->left);
            if(r->right)stk2.push(r->right);
        }
        return same && (!stk1.size() && !stk2.size());
    }
};