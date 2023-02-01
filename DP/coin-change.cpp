class Solution
{
private:
    int solve(int ind, vector<int> &coins, int amount, vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            if (amount % coins[0] == 0)
            {
                return amount / coins[0];
            }
            else
                return 1e9;
        }

        if (dp[ind][amount] != -1)
            return dp[ind][amount];

        int notPick = solve(ind - 1, coins, amount, dp);
        int pick = 1e9;
        if (coins[ind] <= amount)
        {
            pick = 1 + solve(ind, coins, amount - coins[ind], dp);
        }
        return dp[ind][amount] = min(pick, notPick);
    }

public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 1e9));
        // int ans = solve(n-1, coins, amount,dp);
        // if(ans == 1e9 || ans<0) return -1;
        // return ans;

        for (int amt = 0; amt <= amount; amt++)
        {
            if (amt % coins[0] == 0)
                dp[0][amt] = amt / coins[0];
        }

        for (int i = 1; i < n; i++)
        {
            for (int amt = 0; amt <= amount; amt++)
            {
                int notPick = dp[i - 1][amt];
                int pick = 1e9;
                if (amt - coins[i] >= 0)
                {
                    pick = 1 + dp[i][amt - coins[i]];
                }
                dp[i][amt] = min(notPick, pick);
            }
        }

        if (dp[n - 1][amount] >= 1e9)
        {
            return -1;
        }
        else
            return dp[n - 1][amount];
    }
};