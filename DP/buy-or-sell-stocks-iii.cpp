class Solution
{
private:
    int solve(int ind, bool buy, int cap, vector<int> &prices, int &n, vector<vector<vector<int>>> &dp)
    {
        if (ind == n || cap == 0)
            return 0;

        if (dp[ind][buy][cap] != -1)
            return dp[ind][buy][cap];

        if (buy)
        {
            return dp[ind][buy][cap] =
                       max(-prices[ind] + solve(ind + 1, 0, cap, prices, n, dp),
                           solve(ind + 1, 1, cap, prices, n, dp));
        }

        return dp[ind][buy][cap] =
                   max(prices[ind] + solve(ind + 1, 1, cap - 1, prices, n, dp),
                       solve(ind + 1, 0, cap, prices, n, dp));
    }

public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        // days(n) * buy(0/1) * cap(2/1/0)

        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3,-1)));
        // return solve(0, 1, 2, prices, n,dp);

        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));

        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 0; cap <= 2; cap++)
            {
                dp[n][buy][cap] = 0;
            }
        }

        for (int ind = 0; ind < n; ind++)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                dp[ind][buy][0] = 0;
            }
        }

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int cap = 2; cap > 0; cap--)
                {
                    if (buy)
                    {
                        dp[ind][buy][cap] = max(-prices[ind] + dp[ind + 1][0][cap], dp[ind + 1][1][cap]);
                    }
                    else
                    {
                        dp[ind][buy][cap] = max(prices[ind] + dp[ind + 1][1][cap - 1], dp[ind + 1][0][cap]);
                    }
                }
            }
        }
        return dp[0][1][2];
    }
};