//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, 
        pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        int del_row[] = {-1, 0, 1, 0};
        int del_col[] = {0, 1, 0, -1};
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;
            if(row == n-1 && col == m-1)
            {
                return diff;
            }
            for(int i=0; i<4; i++)
            {
                int nr = del_row[i] + row;
                int nc = del_col[i] + col;
                if(nr>=0 && nc>=0 && nr<n && nc<m)
                {
                    int new_effort = max(abs(heights[nr][nc] - heights[row][col]), diff);
                    if(new_effort < dist[nr][nc])
                    {
                        dist[nr][nc] = new_effort;
                        pq.push({new_effort, {nr, nc}});
                    }
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
