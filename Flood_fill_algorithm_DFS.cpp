//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(vector<vector<int>>& image, vector<vector<int>>& ans, int row, int col, 
    int x, int newColor, int del_row[], int del_col[])
    {
        int n = image.size();
        int m = image[0].size();
        ans[row][col] = newColor;
        for(int i=0; i<4; i++)
        {
            int a = row + del_row[i];
            int b = col + del_col[i];
            if(a>=0 && a<n && b>=0 && b<m && image[a][b] == x && ans[a][b] != newColor)
            {
                dfs(image, ans, a, b, x, newColor, del_row, del_col);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        vector<vector<int>> ans = image;
        int del_row[] = {-1, 0, 1, 0};
        int del_col[] = {0, 1, 0, -1};
        
        int x = image[sr][sc];
        dfs(image, ans, sr, sc, x, newColor, del_row, del_col);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
