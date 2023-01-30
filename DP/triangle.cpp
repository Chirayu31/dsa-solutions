class Solution
{
private:
    int solve(int i, int j, int n, vector<vector<int>> &triangle, vector<vector<int>> &dp)
    {
        if (i == n - 1)
            return triangle[i][j];

        if (dp[i][j] != -1)
            return dp[i][j];

        int down = triangle[i][j] + solve(i + 1, j, n, triangle, dp);
        int dig = triangle[i][j] + solve(i + 1, j + 1, n, triangle, dp);

        return dp[i][j] = min(down, dig);
    }

public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<vector<int>> dp(n);

        for (int i = 0; i < n; i++)
        {
            int m = triangle[i].size();
            for (int j = 0; j < m; j++)
            {
                dp[i].push_back(-1);
            }
        }

        // return solve(0,0,n,triangle,dp);

        // base case
        for (int j = 0; j < n; j++)
        {
            dp[n - 1][j] = triangle[n - 1][j];
        }

        // body code
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i; j >= 0; j--)
            {
                int down = dp[i + 1][j] + triangle[i][j];
                int dig = dp[i + 1][j + 1] + triangle[i][j];
                dp[i][j] = min(down, dig);
            }
        }
        return dp[0][0];
    }
};