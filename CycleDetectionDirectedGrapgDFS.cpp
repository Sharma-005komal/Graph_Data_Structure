//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool checkcycle(int node, vector<int> adj[], int vis[], int dfs_vis[])
    {
        vis[node] = 1;
        dfs_vis[node] = 1;
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                if(checkcycle(it, adj, vis, dfs_vis))
                {
                    return true;
                }
            }
            else if(dfs_vis[it])
            {
                return true;
            }
        }
        dfs_vis[node] = 0;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int vis[V], dfs_vis[V];
        memset(vis, 0, sizeof vis);
        memset(dfs_vis, 0, sizeof dfs_vis);
        for(int i=0; i<V; i++)
        {
            if(!vis[i])
            {
                if(checkcycle(i, adj, vis, dfs_vis))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
