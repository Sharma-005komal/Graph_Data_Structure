class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    // code here
	    queue<pair<int, int>> q;
	    q.push({0, 0});
	    int vis[V+1] = {0};
	    vis[0] = 1;
	    while(!q.empty())
	    {
	        auto it = q.front();
	        q.pop();
	        int level = it.first;
	        int temp = it.second;
	        if(temp == X)
	        {
	            return level;
	        }
	        for(auto node:adj[temp])
	        {
	            if(!vis[node])
	            {
	                vis[node] = 1;
	                q.push({level+1, node});
	            }
	        }
	    }
	    return -1;
	}
};
