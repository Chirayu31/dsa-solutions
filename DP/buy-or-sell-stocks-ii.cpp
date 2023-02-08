class Solution
{

    int solve(int ind, bool buy, int n, vector<int> prices, vector<vector<long long>> &dp)
    {
        if (ind == n)
            return 0;

        if (dp[ind][buy] != -1)
            return dp[ind][buy];

        if (buy)
        {
            long long take = -prices[ind] + solve(ind + 1, false, n, prices, dp);
            long long notTake = solve(ind + 1, true, n, prices, dp);
            return dp[ind][buy] = max(take, notTake);
        }

        long long take = prices[ind] + solve(ind + 1, true, n, prices, dp);
        long long notTake = solve(ind + 1, false, n, prices, dp);
        return dp[ind][buy] = max(take, notTake);
    }

public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        // vector<vector<long long>> dp(n, vector<long long>(2,-1));
        // return (int)solve(0, true, n, prices,dp);
        vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));

        dp[n][0] = dp[n][1] = 0;

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                long long profit = 0;
                if (buy)
                {
                    profit = max(-prices[ind] + dp[ind + 1][0], dp[ind + 1][1]);
                }
                else
                    profit = max(prices[ind] + dp[ind + 1][1], dp[ind + 1][0]);
                dp[ind][buy] = profit;
            }
        }
        return dp[0][1];
    }
};