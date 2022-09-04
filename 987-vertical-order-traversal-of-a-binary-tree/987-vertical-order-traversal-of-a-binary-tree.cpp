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
    int upperBoundColumn=INT_MIN;
    int lowerBoundColumn=INT_MAX;
    void preorder(TreeNode* node,vector<pair<int,pair<int,int>>>& vec,int row,int col)
    {
        if(node==nullptr) return;
        upperBoundColumn=max(upperBoundColumn,col);
        lowerBoundColumn=min(lowerBoundColumn,col);
        vec.push_back(make_pair(node->val,make_pair(row,col)));
        preorder(node->left,vec,row+1,col-1);
        preorder(node->right,vec,row+1,col+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<pair<int,pair<int,int>>> vec;
        preorder(root,vec,0,0);
        int numberOfColumns=upperBoundColumn-lowerBoundColumn+1;
        vector<vector<pair<int,int>>> ans(numberOfColumns,vector<pair<int,int>>());
        int nodeValue;
        for(pair<int,pair<int,int>>& p : vec)
        {
            nodeValue=p.first;
            ans[p.second.second-lowerBoundColumn].push_back(make_pair(nodeValue,p.second.first));
        }
        for(int i=0;i<ans.size();i++)
        {
            sort(ans[i].begin(),ans[i].end(),[](const pair<int,int>& p1,const pair<int,int>& p2){
                if(p1.second!=p2.second) return p1.second<p2.second;
                return p1.first<p2.first;
            });
        }
        vector<vector<int>> ans1;
        for(vector<pair<int,int>>& pv : ans)
        {
            vector<int> v;
            for(pair<int,int>& p : pv)
            {
                v.push_back(p.first);
            }
            ans1.push_back(v);
        }
        return ans1;
    }
};