//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int helpaterp(vector<vector<int>> hospital)
    {
        //code here
        int r = hospital.size();
        int c = hospital[0].size();
        int vis[r+1][c+1];
        int count = 0;
        queue<pair<int, pair<int, int>>> q;
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(hospital[i][j] == 2)
                {
                    q.push({0, {i, j}});
                    vis[i][j] = 1;
                }
                else if(hospital[i][j] == 1)
                {
                    count++;
                    vis[i][j] = 0;
                }
                else
                {
                    vis[i][j] = 1;
                }
            }
        }
        int t = 0, cnt=0;
        int del_row[] = {-1, 0, 1, 0};
        int del_col[] = {0, 1, 0, -1};
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int step = it.first;
            int row = it.second.first;
            int col = it.second.second;
            t = max(step, t);
            for(int i=0; i<4; i++)
            {
                int nrow = del_row[i] + row;
                int ncol = del_col[i] + col;
                if(nrow>=0 && ncol>=0 && nrow<r && ncol<c && hospital[nrow][ncol] == 1
                && vis[nrow][ncol] == 0)
                {
                    cnt++;
                    vis[nrow][ncol] = 1;
                    q.push({step+1, {nrow, ncol}});
                }
            }
        }
       if(count == cnt)
        {
            return t;
        }
        return -1;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
