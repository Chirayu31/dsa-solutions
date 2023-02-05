class Solution
{
private:
    int solve(int ind1, int ind2, string &s, string &s2, vector<vector<int>> &dp)
    {
        if (ind1 < 0 || ind2 < 0)
            return 0;

        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];

        if (s[ind1] == s2[ind2])
            return dp[ind1][ind2] = 1 + solve(ind1 - 1, ind2 - 1, s, s2, dp);

        return dp[ind1][ind2] = max(solve(ind1 - 1, ind2, s, s2, dp), solve(ind1, ind2 - 1, s, s2, dp));
    }

public:
    int minInsertions(string s)
    {
        int n = s.size();
        string s2 = s;
        reverse(s2.begin(), s2.end());
        // vector<vector<int>> dp(n, vector<int>(n,-1));
        // return n - solve(n-1, n-1, s, s2,dp);

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] == s2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return n - dp[n][n];
    }
};