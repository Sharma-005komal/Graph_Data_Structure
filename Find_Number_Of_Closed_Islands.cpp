//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    void dfs(vector<vector<int>>& matrix, vector<vector<int>>& vis, int row, int col, int N,
    int M)
    {
        vis[row][col] = 1;
        int del_row[] = {-1, 0, 1, 0};
        int del_col[] = {0, 1, 0, -1};
        for(int i=0; i<4; i++)
        {
            int nrow = del_row[i] + row;
            int ncol = del_col[i] + col;
            if(nrow >= 0 && nrow < N && ncol >= 0 && ncol < M && vis[nrow][ncol] == 0
            && matrix[nrow][ncol] == 1)
            {
                dfs(matrix, vis, nrow, ncol, N, M);
            }
        }
    }
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        // Code here
        vector<vector<int>> vis(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<M; j++)
            {
                if((i == 0 || i == N-1 || j == 0 || j == M-1) && matrix[i][j] == 1)
                {
                    dfs(matrix, vis, i, j, N, M);
                }
            }
        }
        int count = 0;
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<M; j++)
            {
                if(matrix[i][j] == 1 && vis[i][j] == 0)
                {
                    dfs(matrix, vis, i, j, N, M);
                    count++;
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends
