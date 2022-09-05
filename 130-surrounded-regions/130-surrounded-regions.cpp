class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& board,vector<vector<int>>& visited,vector<int>& deltaI,vector<int>& deltaJ)
    {
        // if(i<0 || j<0 || i>=board.size() || j>=board.size()) return;
        visited[i][j]=1;
        int row,col;
        for(int k=0;k<4;k++) 
        {
            row=i+deltaI[k];
            col=j+deltaJ[k];
            if(row>=0 && row<board.size() && col>=0 && col<board[0].size() && visited[row][col]==0 && board[row][col]=='O') dfs(row,col,board,visited,deltaI,deltaJ);
        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        vector<int> deltaI={-1,0,+1,0};
        vector<int> deltaJ={0,+1,0,-1};
        int i,j;
        for(i=0,j=0;j<n;j++) if(board[i][j]=='O' && visited[i][j]==0) dfs(i,j,board,visited,deltaI,deltaJ);
        for(i=m-1,j=0;j<n;j++) if(board[i][j]=='O' && visited[i][j]==0) dfs(i,j,board,visited,deltaI,deltaJ);
        for(i=0,j=0;i<m;i++) if(board[i][j]=='O' && visited[i][j]==0) dfs(i,j,board,visited,deltaI,deltaJ);
        for(i=0,j=n-1;i<m;i++) if(board[i][j]=='O' && visited[i][j]==0) dfs(i,j,board,visited,deltaI,deltaJ);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='O' && visited[i][j]==0) board[i][j]='X';
            }
        }
    }
};