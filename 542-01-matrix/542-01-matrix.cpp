// TLE

// class Solution {
// public:
//     int bfs(int i,int j,vector<vector<int>>& mat)
//     {
//         vector<vector<int>> visited(mat.size(),vector<int>(mat[0].size(),0));
//         queue<pair<int,int>> que;
//         que.push(make_pair(i,j));
//         int level=0,size,row,col;
//         visited[i][j]=1;
//         while(!que.empty())
//         {
//             size=que.size();
//             for(int k=0;k<size;k++)
//             {
//                 row=que.front().first;
//                 col=que.front().second;
//                 que.pop();
//                 if(mat[row][col]==0) return level;
//                 if(row-1>=0 && visited[row-1][col]==0)
//                 {
//                     visited[row-1][col]=1;
//                     que.push(make_pair(row-1,col));
//                 }
//                 if(row+1<mat.size() && visited[row+1][col]==0)
//                 {
//                     visited[row+1][col]=1;
//                     que.push(make_pair(row+1,col));
//                 }
//                 if(col-1>=0 && visited[row][col-1]==0)
//                 {
//                     visited[row][col-1]=1;
//                     que.push(make_pair(row,col-1));
//                 }
//                 if(col+1<mat[0].size() && visited[row][col+1]==0)
//                 {
//                     visited[row][col+1]=1;
//                     que.push(make_pair(row,col+1));
//                 }
//             }
//             level++;            
//         }
//         return -1;
//     }
//     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//         vector<vector<int>> ans(mat.size(),vector<int>(mat[0].size()));
//         for(int i=0;i<mat.size();i++)
//         {
//             for(int j=0;j<mat[0].size();j++)
//             {
//                 ans[i][j]=bfs(i,j,mat);
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> visited(mat.size(),vector<int>(mat[0].size(),0));
        vector<vector<int>> ans=mat;
        queue<pair<int,int>> que;
        int row,col,r,c;
        vector<int> deltaI={-1,0,+1,0};
        vector<int> deltaJ={0,+1,0,-1};
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]==0)
                {
                    que.push(make_pair(i,j));
                    visited[i][j]=1;
                }
            }
        }
        
        while(!que.empty())
        {
            row=que.front().first;
            col=que.front().second;
            que.pop();
            for(int k=0;k<4;k++)
            {
                r=row+deltaI[k];
                c=col+deltaJ[k];
                if(r>=0 && c>=0 && r<mat.size() && c<mat[0].size() && visited[r][c]==0 && mat[r][c]==1)
                {
                    visited[r][c]=1;
                    ans[r][c]=ans[row][col]+1;
                    // string str="for r:";
                    // str+=to_string(r);
                    // str+=" and c:";
                    // str+=to_string(c);
                    // str+=" taking value from row:";
                    // str+=to_string(row);
                    // str+=" and col:";
                    // str+=to_string(col);
                    // cout<<str<<endl;
                    que.push(make_pair(r,c));
                }
            }
            // if(row-1>=0 && visited[row-1][col]==0 && mat[row-1][col]==1)
            // {
            //     visited[row-1][col]=1;
            //     ans[row-1][col]=ans[row][col]+1;
            //     que.push(make_pair(row-1,col));
            // }
        }
        
        return ans;
    }
};