class Solution {
private:
    void bfs(vector<vector<int>>& image,vector<vector<int>>& visited,int row,int col,int color,int curr)
    {
        visited[row][col]=1;
        image[row][col]=color;
        if(row-1>=0 && image[row-1][col]==curr && visited[row-1][col]==0)
            bfs(image,visited,row-1,col,color,curr);
        if(row+1<image.size() && image[row+1][col]==curr && visited[row+1][col]==0)
            bfs(image,visited,row+1,col,color,curr);
        if(col-1>=0 && image[row][col-1]==curr && visited[row][col-1]==0)
            bfs(image,visited,row,col-1,color,curr);
        if(col+1<image[0].size() && image[row][col+1]==curr && visited[row][col+1]==0)
            bfs(image,visited,row,col+1,color,curr);
        
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> visited(image.size(),vector<int>(image[0].size(),0));
        bfs(image,visited,sr,sc,color,image[sr][sc]);
        return image;
    }
};