class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int sum = 0;
        queue<pair<int, int>> q;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1)
                {
                    q.push({i, j});
                }
            }
        }
        int del_r[] = {-1, 0, 1, 0};
        int del_c[] = {0, 1, 0, -1};
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0; i<4; i++)
            {
                int nr = del_r[i] + r;
                int nc = del_c[i] + c;
                if(nr < 0 || nc < 0 || nr >= m || nc >= n)
                {
                    sum++;
                }
                else if(grid[nr][nc] != 1)
                {
                    sum++;
                }
            }
        }
        return sum;
    }
};
