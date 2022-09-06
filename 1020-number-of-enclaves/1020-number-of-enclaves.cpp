// USING DFS
// class Solution {
// public:
//     void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& visited,vector<int>& deltaI,vector<int>& deltaJ)
//     {
//         // cout<<i<<","<<j<<endl;
//         visited[i][j]=1;
//         int row,col;
//         for(int k=0;k<4;k++)
//         {
//             row=i+deltaI[k];
//             col=j+deltaJ[k];
//             // cout<<"OK"<<endl;
//             // cout<<row<<","<<col<<endl;
//             if(row>=0 && row<grid.size() && col>=0 && col<grid[0].size() && visited[row][col]==0 && grid[row][col]==1)
//             {
//                 // cout<<"Entered"<<endl;
//                 dfs(row,col,grid,visited,deltaI,deltaJ);
//             }
//         }
//     }
//     int numEnclaves(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();
//         vector<vector<int>> visited(m,vector<int>(n,0));
//         vector<int> deltaI={-1,0,+1,0};
//         vector<int> deltaJ={0,+1,0,-1};
//         for(int j=0;j<n;j++)
//         {
//             // cout<<"j: "<<j<<endl;
//             if(visited[0][j]==0 && grid[0][j]==1) dfs(0,j,grid,visited,deltaI,deltaJ);
//             if(visited[m-1][j]==0 && grid[m-1][j]==1) dfs(m-1,j,grid,visited,deltaI,deltaJ);
//         }
//         for(int i=0;i<m;i++)
//         {
//             // cout<<"i: "<<i<<endl;
//             if(visited[i][0]==0 && grid[i][0]==1) dfs(i,0,grid,visited,deltaI,deltaJ);
//             if(visited[i][n-1]==0 && grid[i][n-1]==1) dfs(i,n-1,grid,visited,deltaI,deltaJ);
//         }
//         int count=0;
//         for(int i=0;i<m;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 if(grid[i][j]==1 && visited[i][j]==0)
//                 {
//                     // cout<<i<<","<<j<<endl;
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };


// USING BFS

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        vector<int> deltaI={-1,0,+1,0};
        vector<int> deltaJ={0,+1,0,-1};
        queue<pair<int,int>> que;
        
        int i,j,row,col;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i==0 || i==m-1 || j==0 || j==n-1)
                {
                    if(grid[i][j]==1)
                    {
                        que.push(make_pair(i,j));
                        visited[i][j]=1;    
                    }
                }
            }
        }
        
        while(!que.empty())
        {
            i=que.front().first;
            j=que.front().second;
            que.pop();
            for(int k=0;k<4;k++)
            {
                row=i+deltaI[k];
                col=j+deltaJ[k];
                if(row>=0 && row<m && col>=0 && col<n && visited[row][col]==0 && grid[row][col]==1)
                {
                    que.push(make_pair(row,col));
                    visited[row][col]=1;
                }
            }
        }
        
        
        
        int count=0;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(grid[i][j]==1 && visited[i][j]==0)
                {
                    // cout<<i<<","<<j<<endl;
                    count++;
                }
            }
        }
        return count;
    }
};
