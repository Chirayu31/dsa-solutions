class Solution
{
private:
    int solve(int ind, int amount, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            if (amount % coins[0] == 0)
            {
                return 1;
            }
            else
                return 0;
        }
        if (dp[ind][amount] != -1)
            return dp[ind][amount];

        int notPick = solve(ind - 1, amount, coins, dp);
        int pick = 0;

        if (coins[ind] <= amount)
        {
            pick = solve(ind, amount - coins[ind], coins, dp);
        }

        return dp[ind][amount] = pick + notPick;
    }

public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        // vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        // return solve(n-1, amount, coins,dp);
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        for (int amt = 0; amt <= amount; amt++)
        {
            if (amt % coins[0] == 0)
                dp[0][amt] = 1;
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= amount; j++)
            {
                int notPick = dp[i - 1][j];
                int pick = 0;
                if (coins[i] <= j)
                {
                    pick = dp[i][j - coins[i]];
                }
                dp[i][j] = pick + notPick;
            }
        }
        return dp[n - 1][amount];
    }
};