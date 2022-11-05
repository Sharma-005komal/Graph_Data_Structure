//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        int n = grid.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, 
        greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        pq.push({grid[0][0], {0, 0}});
        int del_row[] = {-1, 0, 1, 0};
        int del_col[] = {0, 1, 0, -1};
        vis[0][0] = 1;
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int cost = it.first;
            int row = it.second.first;
            int col = it.second.second;
            if(row == n-1 && col == n-1)
            {
                return cost;
            }
            for(int i=0; i<4; i++)
            {
                int nrow = del_row[i] + row;
                int ncol = del_col[i] + col;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && vis[nrow][ncol] == 0)
                {
                    vis[nrow][ncol] = 1;
                    pq.push({cost+grid[nrow][ncol], {nrow, ncol}});
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
