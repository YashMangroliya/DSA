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
    
    void dfs(TreeNode* root,unordered_map<int,int>& map1)
    {
        if(root==nullptr) return;
        map1[root->val]++;
        if(root->left==nullptr && root->right==nullptr)
        {
            
            int c=0;
            for(auto entry : map1)
            {
                if(entry.second%2!=0) c++;
            }
            if(c<=1) count++;
            map1[root->val]--;
            return;
        }
        dfs(root->left,map1);
        dfs(root->right,map1);
        map1[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int> map1;
        dfs(root,map1);
        return count;
    }
};