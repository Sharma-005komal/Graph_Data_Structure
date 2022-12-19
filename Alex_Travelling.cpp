//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int minimumCost(vector<vector<int>>& flights, int n, int k) {
        // code here
        vector<pair<int, int>> adj[n+1];
        
        for(auto it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> dist(n+1, 1e9);
        dist[k] = 0;
        queue<pair<int, int>> q;
        q.push({k, 0});
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int node = it.first;
            int wt = it.second;
            for(auto i : adj[node])
            {
                int adjNode = i.first;
                int w = i.second;
                if(wt + w < dist[adjNode])
                {
                    dist[adjNode] = dist[node] + w;
                    q.push({adjNode, dist[adjNode]});
                }
            }
        }
        int m = INT_MIN;
        for(int i=1; i<=n; i++)
        {
            m = max(m, dist[i]);
            if(dist[i] == 1e9)
            {
                return -1;
            }
        }
        return m;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends
