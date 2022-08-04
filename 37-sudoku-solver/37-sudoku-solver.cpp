class Solution {
public:
    pair<int,int> findIndex(vector<vector<char>>& board)
    {
        pair<int,int> p;
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                {
                    p.first=i;
                    p.second=j;
                    return p;
                }
            }
        }
        p.first=-1;
        p.second=-1;
        return p;
    }
    bool solve(vector<vector<char>>& board) {
        pair<int,int> p;
        int row,col,i,j,k;
        unordered_set<int> s;
        p=findIndex(board);
        if(p.first==-1) return true;
        // cout<<p.first<<" "<<p.second<<endl;
        
        row= (p.first/3)*3;
        col= (p.second/3)*3;
        s.clear();
        // cout<<row<<" "<<col<<endl;
        for(int i=row;i<row+3;i++)
        {
            for(int j=col;j<col+3;j++)
            {
                if(board[i][j]!='.') s.insert(board[i][j]-48);
            }
        }
        for(int i=1;i<=9;i++)
        {
            if(s.count(i)==0)
            {
                // for(j=0;j<9 && board[p.first][j]!=(i+48);j++);
                // for(k=0;k<9 && board[k][p.second]!=(i+48);k++);
                for(j=0;j<9;j++)
                {
                    if(board[p.first][j]== (i+48)) break;
                    if(board[j][p.second]== (i+48)) break;
                }
                if(j==9)
                {
                    board[p.first][p.second]=i+48;
                    if(solve(board)) return true;
                    board[p.first][p.second]='.';
                }

            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};