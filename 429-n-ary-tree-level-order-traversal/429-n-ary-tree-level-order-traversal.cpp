/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> que;
        if(root!=nullptr) que.push(root);
        vector<vector<int>> ans;
        int size;
        while(!que.empty())
        {
            vector<int> v;
            size=que.size();
            for(int i=0;i<size;i++)
            {
                Node* node=que.front();
                que.pop();
                v.push_back(node->val);
                for(Node* n : node->children)
                {
                    if(n!=nullptr) que.push(n);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};