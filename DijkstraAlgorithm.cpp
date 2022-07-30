//Shortest path in undirected graph

/*******************DIJKSTRA ALGORITHM*********************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, src;
    cin>>n>>m;
    vector<pair<int, int>> g[n+1];  //Graph 
    int a, b, wt;
    for(int i=0; i<m; i++)
    {
        cin>>a>>b>>wt;
        g[a].push_back(make_pair(b,wt));
        g[b].push_back(make_pair(a,wt));
    }
    cin>>src;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;
    vector<int> d(n+1, INT_MAX);
    d[src] = 0;
    p.push(make_pair(0, src));
    
    while(!p.empty())
    {
        int dis = p.top().first;
        int pre = p.top().second;
        p.pop();
        vector<pair<int, int>> :: iterator it;
        for(it = g[pre].begin(); it!=g[pre].end(); it++)
        {
            int next = it->first;
            int next_dis = it->second;
            if(d[next]>d[pre] + next_dis)
            {
                d[next] = d[pre]+next_dis;
                p.push(make_pair(d[next], next));
            }
        }
    }
    
    cout<<"The distance from source"<<src<<":"<<endl;
    
    for(int i=1; i<=n; i++)
    {
        cout<<d[i]<<endl;
    }
    
    return 0;
}
