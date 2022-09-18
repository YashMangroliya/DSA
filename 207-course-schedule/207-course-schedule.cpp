class Solution {
public:
    bool dfs(vector<vector<int>>& adjecencyList,vector<int>& visited,vector<int>& pathVisited,int i)
    {
        if(visited[i]!=0)
        {
            if(pathVisited[i]!=0) return false;
            return true;
        }
        visited[i]=1;
        pathVisited[i]=1;
        for(int node : adjecencyList[i])
        {
            if(dfs(adjecencyList,visited,pathVisited,node)==false) return false;
        }
        pathVisited[i]=0;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // if graph contains cycle then return false
        vector<vector<int>> adjecencyList(numCourses,vector<int>());
        vector<int> visited(numCourses,0),pathVisited(numCourses,0);
        for(int i=0;i<prerequisites.size();i++)
        {
            adjecencyList[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for(int i=0;i<numCourses;i++)
        {
            if(visited[i]==0)
            {
                if(!dfs(adjecencyList,visited,pathVisited,i)) return false;
            }
        }
        return true;
    }
};