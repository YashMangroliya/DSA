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
    int count=1;  // for root node count is already 1
    void preorder(TreeNode* root,vector<int>& nodes)
    {
        if(root==nullptr) return;
        if(root->val >= *max_element(nodes.begin(),nodes.end()))
        {
            count++;
        }
        nodes.push_back(root->val);
        preorder(root->left,nodes);
        preorder(root->right,nodes);
        nodes.pop_back();
    }

    int goodNodes(TreeNode* root) {
    
        vector<int> nodes;
        nodes.push_back(root->val);
        preorder(root->left,nodes);
        preorder(root->right,nodes);
        return count;
    }
};