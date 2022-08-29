class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& grid,vector<vector<int>>& visited)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]=='0' || visited[i][j]==1) return;
        int row=i,col=j;
        visited[row][col]=1;
        
        dfs(row-1,col,grid,visited);
        dfs(row,col+1,grid,visited);
        dfs(row+1,col,grid,visited);
        dfs(row,col-1,grid,visited);
        
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        int count=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(visited[i][j] || grid[i][j]=='0') continue;
                dfs(i,j,grid,visited);
                count++;
            }
        }
        return count;
    }
};