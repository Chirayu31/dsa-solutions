class Solution
{
private:
    int bfs(int row, int col, vector<vector<int>> grid, vector<vector<int>> &vis)
    {
        int area = 0;
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;

        q.push({row, col});
        vis[row][col] = 1;
        int del[] = {0, -1, 0, 1, 0};

        while (!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            area++;
            // cout<<r<<" "<<c<<" "<<", ";

            for (int i = 0; i < 4; i++)
            {
                int newr = r + del[i];
                int newc = c + del[i + 1];

                if (newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] == 1 &&
                    !vis[newr][newc])
                {
                    q.push({newr, newc});
                    vis[newr][newc] = 1;
                }
            }
        }
        return area;
    }

public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        int maxArea = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == 1)
                {
                    int area = bfs(i, j, grid, vis);
                    maxArea = max(area, maxArea);
                }
            }
        }
        return maxArea;
    }
};