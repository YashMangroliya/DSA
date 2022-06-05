class Solution {
public:
    int ans=0;
    bool isSafe(vector<string> &board,int row,int col,int n)
    {
        int r,c;
        for(r=row,c=col-1;c>=0;c--)
        {
            if(board[r][c]=='Q') return false;
        }
        for(r=row-1,c=col-1;c>=0 && r>=0;c--,r--)
        {
            if(board[r][c]=='Q') return false;
        }
        for(r=row+1,c=col-1;c>=0 && r<n;c--,r++)
        {
            if(board[r][c]=='Q') return false;
        }
        return true;
    }
    
    void solve(int col,vector<string> &board,int n)
    {
        if(col==n)
        {
            ans++;
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(isSafe(board,row,col,n))
            {
                board[row][col]='Q';
                solve(col+1,board,n);
                board[row][col]='.';
            }
        }
    }

    int totalNQueens(int n) {
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++) board[i]=s;
        
        solve(0,board,n);
        return ans;
    }
};