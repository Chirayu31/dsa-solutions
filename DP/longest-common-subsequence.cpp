class Solution
{
private:
    int solve(int ind1, int ind2, string &text1, string &text2, vector<vector<int>> &dp)
    {
        if (ind1 < 0 || ind2 < 0)
            return 0;

        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];

        if (text1[ind1] == text2[ind2])
        {
            return dp[ind1][ind2] = 1 + solve(ind1 - 1, ind2 - 1, text1, text2, dp);
        }

        return dp[ind1][ind2] = max(solve(ind1 - 1, ind2, text1, text2, dp), solve(ind1, ind2 - 1, text1, text2, dp));
    }

public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n1 = text1.size(), n2 = text2.size();
        // vector<vector<int>> dp(n1, vector<int>(n2, -1));
        // return solve(n1-1, n2-1, text1, text2, dp);
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));

        for (int i = 0; i <= n1; i++)
            dp[i][0] = 0;
        for (int j = 0; j <= n2; j++)
            dp[0][j] = 0;

        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= n2; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n1][n2];
    }
};