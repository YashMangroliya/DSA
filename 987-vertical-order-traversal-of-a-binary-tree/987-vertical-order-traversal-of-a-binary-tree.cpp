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
/*
LOGIC:

Step 1:
I will traverse over the whole tree and will add all the nodes in a vector.
This vector will be a vector of pairs, first value of this pair will be nodeValue and second value of this pair will be a pair of row and column.

Step 2:
After this I will make a new vector , will traverse on the previous vector and add value to this vector by taking the column value as index value.


Step 3:
will sort this just previous vector on the basis of row number, if row number if same then on the basis of nodeValue

Step 4:
After this will make another vector, will traverse the just previous vector and add to this vector(in previous vector we were adding pairs so that we can sort on basis of row, now so that it has been sorted we will omitt the column value and will only add the nodeValue to vector which is required as answer)
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
        preorder(root,vec,0,0); // Step 1
        int numberOfColumns=upperBoundColumn-lowerBoundColumn+1;
        vector<vector<pair<int,int>>> ans(numberOfColumns,vector<pair<int,int>>());
        int nodeValue;
        // Step 2
        for(pair<int,pair<int,int>>& p : vec)
        {
            nodeValue=p.first;
            ans[p.second.second-lowerBoundColumn].push_back(make_pair(nodeValue,p.second.first));
        }
        // Step 3
        for(int i=0;i<ans.size();i++)
        {
            sort(ans[i].begin(),ans[i].end(),[](const pair<int,int>& p1,const pair<int,int>& p2){
                if(p1.second!=p2.second) return p1.second<p2.second;
                return p1.first<p2.first;
            });
        }
        // Step 4
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