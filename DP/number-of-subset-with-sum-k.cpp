#include <bits/stdc++.h>

int solve(int ind, vector<int> &nums, int target, vector<vector<int>> &dp)
{

    if (ind == 0)
    {
        if (target == 0 && nums[0] == 0)
            return 2;
        if (nums[0] == target || target == 0)
            return 1;
        return 0;
    }

    if (dp[ind][target] != -1)
        return dp[ind][target];

    int pick = 0;

    if (nums[ind] <= target)
        pick = solve(ind - 1, nums, target - nums[ind], dp);

    int notPick = solve(ind - 1, nums, target, dp);

    return dp[ind][target] = pick + notPick;
}

int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    int n = num.size();
    // vector<vector<int>> dp(n, vector<int>(tar+1, -1));
    // return solve(n-1, num, tar, dp);

    vector<vector<int>> dp(n, vector<int>(tar + 1, 0));

    for (int i = 0; i < n; i++)
        dp[i][0] = 1;
    if (num[0] <= tar)
        dp[0][num[0]] = 1;
    if (num[0] == 0)
        dp[0][0] = 2;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= tar; j++)
        {
            int pick = 0, notPick = dp[i - 1][j];
            if (num[i] <= j)
            {
                pick = dp[i - 1][j - num[i]];
            }
            dp[i][j] = pick + notPick;
        }
    }

    return dp[n - 1][tar];
}
