//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& mat, 
    int del_row[], int del_col[], int n, int m)
    {
        vis[row][col] = 1;
        for(int i=0; i<4; i++)
        {
            int nr = del_row[i] + row;
            int nc = del_col[i] + col;
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && mat[nr][nc] == 'O')
            {
                dfs(nr, nc, vis, mat, del_row, del_col, n, m);
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        //traverse first row && last row
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int del_row[] = {-1, 0, 1, 0};
        int del_col[] = {0, 1, 0, -1};
        for(int i=0; i<m; i++)
        {
            if(!vis[0][i] && mat[0][i] == 'O')
            {
                dfs(0, i, vis, mat, del_row, del_col, n, m);
            }
            if(!vis[n-1][i] && mat[n-1][i] == 'O')
            {
                dfs(n-1, i, vis, mat, del_row, del_col, n, m);
            }
        }
        
        //traverse frist col and last col
        for(int i=0; i<n; i++)
        {
            if(!vis[i][0] && mat[i][0] == 'O')
            {
                dfs(i, 0, vis, mat, del_row, del_col, n, m);
            }
            if(!vis[i][m-1] && mat[i][m-1] == 'O')
            {
                dfs(i, m-1, vis, mat, del_row, del_col, n, m);
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(vis[i][j]==0 && mat[i][j] == 'O')
                {
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends
