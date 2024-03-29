/*****Krushkal Algorithm*****/


#include <bits/stdc++.h>
using namespace std;

struct node
{
    int u, v, wt;
    node(int first, int second, int weight)
    {
        u = first;
        v = second;
        wt = weight;
    }
};

bool comp(node a, node b)
{
    return a.wt < b.wt;
}

int find_parent(int u, vector<int>& parent)
{
    if(u == parent[u])
    {
        return u;
    }
    return parent[u] = find_parent(parent[u], parent);
}

void unionn(int u, int v, vector<int>& parent, vector<int>& rank)
{
    u = find_parent(u, parent);
    v = find_parent(v, parent);
   
    if(rank[u] < rank[v])
    {
        parent[u] = v;
    }
   
    else if(rank[v] < rank[u])
    {
        parent[v] = u;
    }
   
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

int main()
{
    int n, m;
    cin>>n>>m;
    vector<node> edge;
    for(int i=0; i<m; i++)
    {
        int u, v, wt;
        cin>>u>>v>>wt;
        edge.push_back(node(u, v, wt));
    }
    sort(edge.begin(), edge.end(), comp);
   
    vector<int> parent(n);
    for(int i=0; i<n; i++)
    {
        parent[i] = i;
    }
   
    vector<int> rank(n, 0);
   
    int cost = 0;
   
    vector<pair<int, int>> mst;
   
    for(auto it:edge)
    {
        if(find_parent(it.v, parent) != find_parent(it.u, parent))
        {
            cost += it.wt;
            mst.push_back({it.u, it.v});
            unionn(it.u, it.v, parent, rank);
        }
    }
   
    cout<<cost<<endl;
   
    for(auto it:mst)
    {
        cout<<it.first<<"-"<<it.second<<endl;
    }

    return 0;
}
