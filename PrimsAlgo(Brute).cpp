/*******************PRIM'S ALGORITHM***********************/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;
    vector<pair<int, int>> g[n+1];
    
    int a, b, wt;
    for(int i=0; i<m; i++)
    {
        cin>>a>>b>>wt;
        g[a].push_back(make_pair(b, wt));
        g[b].push_back(make_pair(a, wt));
    }
    
    int p[n];    // parent array which store node's parent
    int k[n];    //  key array stores minimum distance from particular node
    bool mst[n];   // minimum spanning tree array store to check whether a node is visited or node
    
    for(int i=0; i<n; i++)
    {
        k[i] = INT_MAX, mst[i] = false;
        p[i] = -1;
    }
    
    k[0] = 0;
    p[0] = -1;
    
    for(int count=0; count<n-1; count++)
    {
        int mini = INT_MAX, u;
        
        //find minimum distance from key array
        for(int v=0; v<n; v++)
        {
            if(mst[v] == false && k[v] < mini)
            {
                mini = k[v];
                u = v;
            }
        }
        
        mst[u] = true;
        
        //update all keys by their minimum distance
        for(auto it:g[u])
        {
            int v = it.first;
            int w = it.second;
            if(mst[v] == false && w<k[v])
            {
                p[v] = u;
                k[v] = w;
            }
        }
    }
    
    //print distance
    for(int i=1; i<n; i++)
    {
        cout<<p[i]<<"-"<<i<<endl;
    }
    

    return 0;
}
