/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> set1,set2;
        TreeNode* tmp=root;
        while(1)
        {
            set1.push_back(tmp);
            if(tmp->val==p->val) break;
            if(p->val>tmp->val)
            {
                tmp=tmp->right;
            }
            else
            {
                tmp=tmp->left;
            }
        }
        tmp=root;
        while(1)
        {
            set2.push_back(tmp);
            if(tmp->val==q->val) break;
            if(q->val>tmp->val)
            {
                tmp=tmp->right;
            }
            else
            {
                tmp=tmp->left;
            }
        }
        
        for(int i=set1.size()-1;i>=0;i--)
        {
            if(find(set2.begin(),set2.end(),set1[i])!=set2.end()) return set1[i];
        }
        return nullptr;
    }
};