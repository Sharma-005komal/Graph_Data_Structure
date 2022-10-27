//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    pair<int, int> a, b;
	    a.first = KnightPos[0];
	    a.second = KnightPos[1];
	    b.first = TargetPos[0];
	    b.second = TargetPos[1];
	    queue<pair<int, pair<int, int>>> q;
	    q.push({0, {a.first, a.second}});
	    bool vis[N+1][N+1];
	    for(int i=1; i<=N; i++)
	    {
	        for(int j=1; j<=N; j++)
	        {
	            vis[i][j] = 0;
	        }
	    }
	    int del_row[] = {-2, -1, 1, 2, -2, -1, 1, 2};
	    int del_col[] = {-1, -2, -2, -1, 1, 2, 2, 1};
	    while(!q.empty())
	    {
	        int dis = q.front().first;
	        int row = q.front().second.first;
	        int col = q.front().second.second;
	        q.pop();
	        if(row == b.first && col == b.second)
	        {
	            return dis;
	        }
	        for(int i=0; i<8; i++)
	        {
	            int nrow = del_row[i] + row;
	            int ncol = del_col[i] + col;
	            if(nrow >= 1 && nrow <= N && ncol >= 1 && ncol <= N
	            && !vis[nrow][ncol])
	            {
	                vis[nrow][ncol] = 1;
	                q.push({dis + 1, {nrow, ncol}});
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
