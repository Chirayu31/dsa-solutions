class Solution
{
private:
    int solve(int i, int j, vector<vector<int>> &matrix, int n, vector<vector<int>> &dp)
    {
        if (i < 0 || j < 0)
            return 1e9;
        if (i == 0)
            return matrix[i][j];

        if (dp[i][j] != -1)
            return dp[i][j];

        int digLeft = solve(i - 1, j - 1, matrix, n, dp);

        int up = solve(i - 1, j, matrix, n, dp);

        int digRight = 1e9;

        if (j + 1 < n)
        {
            digRight = solve(i - 1, j + 1, matrix, n, dp);
        }

        return dp[i][j] = matrix[i][j] + min(digLeft, min(up, digRight));
    }

public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        // int ans = 1e9;
        // for(int i=0;i<n;i++){
        //     ans = min(solve(n-1, i, matrix,n,dp), ans);
        // }
        // return ans;

        for (int col = 0; col < n; col++)
            dp[0][col] = matrix[0][col];

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int digLeft = 1e9, digRight = 1e9, up = 1e9;

                if (j - 1 >= 0)
                    digLeft = matrix[i][j] + dp[i - 1][j - 1];
                if (j + 1 < n)
                    digRight = matrix[i][j] + dp[i - 1][j + 1];
                up = matrix[i][j] + dp[i - 1][j];

                dp[i][j] = min(digLeft, min(digRight, up));
            }
        }
        int ans = 1e9;

        for (int i = 0; i < n; i++)
        {
            ans = min(ans, dp[n - 1][i]);
        }
        return ans;
    }
};