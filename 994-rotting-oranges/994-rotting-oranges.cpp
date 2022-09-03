class Solution {
private:
    // int gAns=0;
    // void bfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& visited,int lAns)
    // {
    //     if(lAns>gAns) gAns=lAns;
    //     visited[i][j]=1;
    //     grid[i][j]=2;
    //     if(i-1>=0 && grid[i-1][j]==1 && visited[i-1][j]==0)
    //         bfs(i-1,j,grid,visited,lAns+1);
    //     if(i+1<grid.size() && grid[i+1][j]==1 && visited[i+1][j]==0)
    //         bfs(i+1,j,grid,visited,lAns+1);
    //     if(j-1>=0 && grid[i][j-1]==1 && visited[i][j-1]==0)
    //         bfs(i,j-1,grid,visited,lAns+1);
    //     if(j+1<grid[0].size() && grid[i][j+1]==1 && visited[i][j+1]==0)
    //         bfs(i,j+1,grid,visited,lAns+1);
    // }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        queue<pair<int,int>> que;
        int numberOf1=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2 && visited[i][j]==0)
                {
                    que.push(make_pair(i,j));
                    visited[i][j]=1;
                }
                if(grid[i][j]==1) numberOf1=1;
            }
        }
        if(que.size()==0 && numberOf1==0) return 0;
        if(que.size()==0 && numberOf1==1) return -1;
        pair<int,int> p;
        int i,j;
        int ans=-1,size;
        while(!que.empty())
        {
            ans++;
            size=que.size();
            for(int k=0;k<size;k++)
            {
                p=que.front();
                que.pop();
                i=p.first;
                j=p.second;
                
                if(i-1>=0 && grid[i-1][j]==1 && visited[i-1][j]==0)
                {
                    visited[i-1][j]=1;
                    grid[i-1][j]=2;
                    que.push(make_pair(i-1,j));
                }
                if(i+1<grid.size() && grid[i+1][j]==1 && visited[i+1][j]==0)
                {
                    visited[i+1][j]=1;
                    grid[i+1][j]=2;
                    que.push(make_pair(i+1,j));
                }
                if(j-1>=0 && grid[i][j-1]==1 && visited[i][j-1]==0)
                {
                    visited[i][j-1]=1;
                    grid[i][j-1]=2;
                    que.push(make_pair(i,j-1));
                }
                if(j+1<grid[0].size() && grid[i][j+1]==1 && visited[i][j+1]==0)
                {
                    visited[i][j+1]=1;
                    grid[i][j+1]=2;
                    que.push(make_pair(i,j+1));
                }
                
            }
        }
        
        
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    return -1;
                }
            }
        }
        
        return ans;
    }
};