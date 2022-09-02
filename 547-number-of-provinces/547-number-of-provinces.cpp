class Solution {
private:
    void dfs(int index,vector<vector<int>>& isConnected,vector<int>& visited)
    {
        visited[index]=1;
        for(int i=0;i<isConnected.size();i++)
        {
            if(isConnected[index][i]!=0 && visited[i]==0)
            {
                dfs(i,isConnected,visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V=isConnected.size();
        vector<int> visited(V,0);
        int count=0;
        for(int i=0;i<V;i++)
        {
            if(visited[i]==0)
            {
                dfs(i,isConnected,visited);
                count++;
            }
        }
        return count;
    }
};