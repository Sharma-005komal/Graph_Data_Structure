//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid, 
    vector<pair<int, int>>& ans, int row0, int col0)
    {
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        ans.push_back({row-row0, col-col0});
        int del_row[] = {-1, 0, 1, 0};
        int del_col[] = {0, 1, 0, -1};
        for(int i=0; i<4; i++)
        {
            int nr = del_row[i] + row;
            int nc = del_col[i] + col;
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc] == 1 && !vis[nr][nc])
            {
                dfs(nr, nc, vis, grid, ans, row0, col0);
            }
        }
    }
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> st;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!vis[i][j] && grid[i][j] == 1)
                {
                    vector<pair<int, int>> ans;
                    dfs(i, j, vis, grid, ans, i, j);
                    st.insert(ans);
                }
            }
        }
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends
