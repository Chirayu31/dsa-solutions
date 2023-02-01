class Solution
{
private:
    int mod = (int)1e9 + 7;

    int solve(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
    {

        if (ind == 0)
        {
            if (arr[0] == 0 && target == 0)
                return 2;
            if (arr[0] == target || target == 0)
                return 1;
            return 0;
        }

        if (dp[ind][target] != -1)
            return dp[ind][target];

        int notPick = solve(ind - 1, target, arr, dp);
        int pick = 0;
        if (arr[ind] <= target)
            pick = solve(ind - 1, target - arr[ind], arr, dp);

        return dp[ind][target] = (pick + notPick) % (mod);
    }

public:
    int countPartitions(int n, int d, vector<int> &arr)
    {
        // Code here
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += arr[i];

        if ((sum - d) % 2 != 0)
            return 0;
        if (sum - d < 0)
            return 0;
        int target = (sum - d) / 2;

        // vector<vector<int>> dp(n, vector<int>(target+1, -1));

        // return solve(n-1, target, arr, dp);

        vector<vector<int>> dp(n, vector<int>(target + 1, 0));

        if (arr[0] == 0)
            dp[0][0] = 2;
        else
            dp[0][0] = 1;

        if (arr[0] <= target && arr[0] != 0)
            dp[0][arr[0]] = 1;

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= target; j++)
            {

                int notPick = dp[i - 1][j];
                int pick = 0;
                if (arr[i] <= j)
                    pick = dp[i - 1][j - arr[i]];

                dp[i][j] = (pick + notPick) % (mod);
            }
        }
        return (dp[n - 1][target]);
    }
};