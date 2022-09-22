class Solution {
public:
    bool dfs(vector<vector<int>>& graph,vector<int>& visited,vector<int>& pathVisited,int i)
    {
        visited[i]=1;
        pathVisited[i]=1;
        for(int index : graph[i])
        {
            if(visited[index]==0)
            {
                if(dfs(graph,visited,pathVisited,index)==false)
                {
                    visited[index]=2;
                    pathVisited[index]=0;
                    return false;
                }
            }
            else 
            {
                if(pathVisited[index]!=0 || visited[index]==2)
                {
                    visited[index]=2;
                    pathVisited[index]=0;
                    return false;
                }
            }
        }
        pathVisited[i]=0;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> visited(n,0),pathVisited(n,0),ans;
        for(int i=0;i<n;i++)
        {
            if(visited[i]==0)
            {
                if(dfs(graph,visited,pathVisited,i)==false)
                {
                    visited[i]=2;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(visited[i]!=2) ans.push_back(i);
        }
        return ans;
    }
};