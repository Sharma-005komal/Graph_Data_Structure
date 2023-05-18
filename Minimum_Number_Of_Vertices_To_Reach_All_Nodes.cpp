class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<pair<int, int>> adj;
        for(auto it : edges)
        {
            adj.push_back({it[0], it[1]});
        }
        vector<int> topoin(n, 0), topoout(n, 0);
        for(auto it : edges)
        {
            topoout[it[0]]++;
            topoin[it[1]]++;
        }
        for(int i=0; i<n; i++)
        {
            if(topoin[i] == 0 && topoout[i] != 0)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
