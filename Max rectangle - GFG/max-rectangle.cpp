// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  
    int getMaxAreaOfReactagleInHistogram(vector<int> heights)
    {
        int n=heights.size();
        stack<int> s;
        int height,width,maxArea;
        for(int i=0;i<=n;i++)
        {
            while(!s.empty() && (i==n || heights[s.top()]>=heights[i]))
            {
                height=heights[s.top()];
                s.pop();
                if(s.empty()) width=i;
                else width=i-s.top()-1;
                maxArea=max(maxArea,height*width);
            }
            s.push(i);
        }
        return maxArea;
    }

    int maxArea(int matrix[MAX][MAX], int n, int m) {
        vector<int> v(m,0);
        int maxArea=0;
        int i,j;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(matrix[i][j]==1)
                {
                    v[j]++;
                }
                else {
                    v[j]=0;
                }
            }
            maxArea=max(maxArea,getMaxAreaOfReactagleInHistogram(v));
        }
        return maxArea;
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends