//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    // Code here
	    queue<pair<int, pair<int, int>>> q;
	    q.push({0, {KnightPos[0], KnightPos[1]}});
	    int del_row[] = {-2, -1, 1, 2, -2, -1, 1, 2};
	    int del_col[] = {-1, -2, -2, -1, 1, 2, 2, 1};
	    bool vis[N+1][N+1];
	    for(int i=1; i<=N; i++)
	    {
	        for(int j=1; j<=N; j++)
	        {
	            vis[i][j] = false;
	        }
	    }
	    while(!q.empty())
	    {
	        auto it = q.front();
	        q.pop();
	        int minstep = it.first;
	        int row = it.second.first;
	        int col = it.second.second;
	        if(row == TargetPos[0] && col == TargetPos[1])
	        {
	            return minstep;
	        }
	        for(int i=0; i<8; i++)
	        {
	            int nrow = row + del_row[i];
	            int ncol = col + del_col[i];
	            if(nrow>=1 && ncol >=1 && nrow<=N && ncol<=N && !vis[nrow][ncol])
	            {
	                vis[nrow][ncol] = true;
	                q.push({minstep+1, {nrow, ncol}});
	            }
	        }
	    }
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
