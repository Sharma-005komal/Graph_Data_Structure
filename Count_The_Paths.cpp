//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    // Code here
	    vector<int> adj[n];
	    if(s == d)
	    {
	        return 1;
	    }
	    for(auto it : edges)
	    {
	        adj[it[0]].push_back(it[1]);
	    }
	    queue<int> q;
	    q.push(s);
	   
	    int count = 0;
	    while(!q.empty())
	    {
	        int node = q.front();
	        q.pop();
	        for(auto it : adj[node])
	        {
	            if(it == d)
	            {
	                count++;
	            }
	            else
	            {
	                q.push(it);
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
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
