//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void bfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int row, int col, 
    int n, int m)
    {
        queue<pair<int, int>> q;
        q.push({row, col});
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int d_r=-1; d_r<=1; d_r++)
            {
                for(int d_c=-1; d_c<=1; d_c++)
                {
                    int d_row = d_r + x;
                    int d_col = d_c + y;
                    if(d_row>=0 && d_row<n && d_col>=0 && d_col<m 
                    && grid[d_row][d_col] == '1' && !vis[d_row][d_col])
                    {
                        vis[d_row][d_col] = 1;
                        q.push({d_row, d_col});
                    }
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!vis[i][j] && grid[i][j] == '1')
                {
                    count++;
                    bfs(grid, vis, i, j, n, m);
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends
