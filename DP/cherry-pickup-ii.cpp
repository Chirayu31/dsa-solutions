class Solution
{
private:
    int solve(int i, int j1, int j2, int n, int m, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
    {
        if (j1 < 0 || j2 < 0 || j1 >= m || j2 >= m)
            return -1e8;

        if (i == n - 1)
        {
            if (j1 == j2)
                return grid[i][j1];
            else
                return grid[i][j1] + grid[i][j2];
        }
        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];

        int maxi = INT_MIN;
        for (int d1 = -1; d1 <= 1; d1++)
        {
            for (int d2 = -1; d2 <= 1; d2++)
            {

                int value = 0;

                if (j1 == j2)
                    value += grid[i][j1];
                else
                    value += grid[i][j1] + grid[i][j2];

                value += solve(i + 1, j1 + d1, j2 + d2, n, m, grid, dp);

                maxi = max(value, maxi);
            }
        }
        return dp[i][j1][j2] = maxi;
    }

public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>>
            dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        // return solve(0, 0, m-1, n, m, grid,dp);

        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                if (j1 == j2)
                    dp[n - 1][j1][j2] = grid[n - 1][j1];
                else
                    dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
            }
        }

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j1 = 0; j1 < m; j1++)
            {
                for (int j2 = 0; j2 < m; j2++)
                {
                    int maxi = -1e9;

                    for (int d1 = -1; d1 < 2; d1++)
                    {
                        for (int d2 = -1; d2 < 2; d2++)
                        {
                            int ans;

                            if (j1 == j2)
                                ans = grid[i][j2];
                            else
                                ans = grid[i][j1] + grid[i][j2];

                            if (j1 + d1 < 0 || j1 + d1 >= m || j2 + d2 < 0 || j2 + d2 >= m)
                                ans += -1e9;
                            else
                                ans += dp[i + 1][j1 + d1][j2 + d2];

                            maxi = max(ans, maxi);
                        }
                    }

                    dp[i][j1][j2] = maxi;
                }
            }
        }

        return dp[0][0][m - 1];
    }
};