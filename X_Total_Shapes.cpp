//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find the number of 'X' total shapes.
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid,
    int del_row[], int del_col[])
    {
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<4; i++)
        {
            int n_row = del_row[i] + row;
            int n_col = del_col[i] + col;
            if(n_row >= 0 && n_row < n && n_col >= 0 && n_col < m &&
            grid[n_row][n_col] == 'X' && !vis[n_row][n_col])
            {
                dfs(n_row, n_col, vis, grid, del_row, del_col);
            }
        }
    }
    int xShape(vector<vector<char>>& grid) 
    {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int count = 0;
        int del_row[] = {-1, 0, 1, 0};
        int del_col[] = {0, 1, 0, -1};
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!vis[i][j] && grid[i][j] == 'X')
                {
                    dfs(i, j, vis, grid, del_row, del_col);
                    count++;
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}
// } Driver Code Ends
