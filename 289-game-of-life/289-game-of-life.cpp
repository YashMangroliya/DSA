class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n,m,i,j,count;
        n=board.size();
        m=board[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                count=0;
                if(i-1>=0 && j-1>=0 && board[i-1][j-1]==1) count++;
                if(i-1>=0 && board[i-1][j]==1) count++;
                if(i-1>=0 && j+1<m && board[i-1][j+1]==1) count++;
                if(j-1>=0 && board[i][j-1]==1) count++;
                if(j+1<m && board[i][j+1]==1) count++;
                if(i+1<n && j-1>=0 && board[i+1][j-1]==1) count++;
                if(i+1<n && board[i+1][j]==1) count++;
                if(i+1<n && j+1<m && board[i+1][j+1]==1) count++;
                
                if(count<2) ans[i][j]=0;
                else if((count==2 || count==3) && board[i][j]==1) ans[i][j]=1;
                else if(count==3 && board[i][j]==0) ans[i][j]=1;
                else if(count>3) ans[i][j]=0;
                
            }
        }
        board=ans;
    }
};