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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> que;
        vector<double> ans;
        double avg,sum;
        que.push(root);
        int size;
        while(!que.empty())
        {
            size=que.size();
            sum=0;
            for(int i=0;i<size;i++)
            {
                sum+=que.front()->val;
                if(que.front()->left!=nullptr) que.push(que.front()->left);
                if(que.front()->right!=nullptr) que.push(que.front()->right);
                que.pop();
            }
            avg=sum/size;
            ans.push_back(avg);
        }
        
        return ans;
    }
};