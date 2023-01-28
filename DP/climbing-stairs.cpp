class Solution
{
private:
    int util(int idx, int n, vector<int> &dp)
    {
        if (idx > n)
            return 0;
        else if (idx == n)
            return 1;

        if (dp[idx] != -1)
            return dp[idx];

        int oneStep = util(idx + 1, n, dp);
        int twoStep = util(idx + 2, n, dp);

        return dp[idx] = oneStep + twoStep;
    }

public:
    int climbStairs(int n)
    {

        vector<int> dp(n + 1, -1);
        dp[0] = 1, dp[1] = 1;

        // return util(0, n, dp); -> memoized
        // below is the tabulation
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};