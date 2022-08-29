class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& grid,vector<vector<int>>& visited)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]=='0' || visited[i][j]==1) return;
        int row=i,col=j;
        visited[row][col]=1;
        // vector<int> deltaI={-1,0,+1,0};
        // vector<int> deltaJ={0,+1,0,-1};
//         for(int k=0;k<4;k++)
//         {
//             row=i+deltaI[k];
//             col=j+deltaJ[k];
//             // if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size() || visited[row][col]==1 || grid[row][col]=='0') continue;
            
//             // if(row>=0 && row<grid.size() && col>=0 && col<grid[0].size() && visited[row][col]!=1 && grid[row][col]!='0') dfs(row,col,grid,visited);
//             dfs(row,col,grid,visited);
//         }
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