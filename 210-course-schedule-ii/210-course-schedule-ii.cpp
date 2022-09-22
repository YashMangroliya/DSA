class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        // code to make adjecency List form given data starts here
        vector<vector<int>> adjecencyList(numCourses,vector<int>());
        for(int i=0;i<prerequisites.size();i++)
        {
            adjecencyList[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        // code to make adjecency List form given data ends here
        int V=numCourses;
        vector<int> indegree(V,0);
	    queue<int> que;
	    vector<int> ans;
	    int node;
	    for(int i=0;i<V;i++)
	    {
	        for(int index : adjecencyList[i])
	        {
	            indegree[index]++;
	        }
	    }
	    for(int i=0;i<V;i++) 
	    {
	        if(indegree[i]==0) que.push(i);
	    }
	    while(!que.empty())
	    {
	        node=que.front();
	        que.pop();
	        ans.push_back(node);
	        for(int index : adjecencyList[node])
	        {
	            indegree[index]--;
	            if(indegree[index]==0) que.push(index);
	        }
	    }
	    if(ans.size()==V) return ans;
        return vector<int>();
    }
};