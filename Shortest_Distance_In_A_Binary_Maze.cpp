//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, pair<int, int>>> q;
        int del_row[] = {-1, 0, 1, 0};
        int del_col[] = {0, 1, 0, -1};
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[source.first][source.second] = 0;
        q.push({0, {source.first, source.second}});
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            if(r == destination.first && c == destination.second)
            {
                return dis;
            }
            for(int i=0; i<4; i++)
            {
                int n_row = r + del_row[i];
                int n_col = c + del_col[i];
                if(n_row>=0 && n_row<n && n_col>=0 && n_col<m && 
                grid[n_row][n_col] == 1 && dis + 1 < dist[n_row][n_col])
                {
                    dist[n_row][n_col] = 1 + dis;
                    q.push({dis+1, {n_row, n_col}});
                }
            }
        }
        return -1;
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends
