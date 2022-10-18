//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int tm = 0;
        int del_row[] = {-1, 0, 1, 0};
        int del_col[] = {0, 1, 0, -1};
        int n = grid.size();
        int m = grid[0].size();
        int vis[n][m];
        int cnt = 0;
        queue<pair<pair<int, int>, int>> q;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
                else
                {
                    vis[i][j] = 0;
                }
                if(grid[i][j] == 1)
                {
                    cnt++;
                }
            }
        }
        int count = 0;
        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            tm = max(tm, t);
            q.pop();
            for(int i=0; i<4; i++)
            {
                int r = row + del_row[i];
                int c = col + del_col[i];
                if(r>=0 && r<n && c>=0 && c<m && grid[r][c] == 1 && vis[r][c] == 0)
                {
                    q.push({{r, c}, t+1});
                    vis[r][c] = 2;
                    count++;
                }
            }
        }
        if(count != cnt)
        {
            return -1;
        }
        return tm;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
