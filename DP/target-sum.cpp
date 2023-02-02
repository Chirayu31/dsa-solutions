class Solution
{
private:
    int solve(int ind, int diff, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            if (diff == 0 && nums[0] == 0)
                return 2;
            if (diff == 0 || nums[0] == diff)
                return 1;
            return 0;
        }
        if (dp[ind][diff] != -1)
            return dp[ind][diff];

        int notPick = solve(ind - 1, diff, nums, dp);
        int pick = 0;
        if (nums[ind] <= diff)
        {
            pick = solve(ind - 1, diff - nums[ind], nums, dp);
        }

        return dp[ind][diff] = pick + notPick;
    }

public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();
        int sum = 0;

        for (int i = 0; i < n; i++)
            sum += nums[i];

        if ((sum - target) % 2 != 0)
            return 0;
        if (sum < target)
            return 0;

        int diff = (sum - target) / 2;
        // vector<vector<int>> dp(n, vector<int>(diff+1,-1));

        // return solve(n-1, diff, nums, dp);
        vector<vector<int>> dp(n, vector<int>(diff + 1, 0));

        if (nums[0] <= diff)
            dp[0][nums[0]] = 1;

        if (nums[0] == 0)
            dp[0][0] = 2;
        else
            dp[0][0] = 1;

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= diff; j++)
            {
                int notPick = dp[i - 1][j];
                int pick = 0;
                if (nums[i] <= j)
                {
                    pick = dp[i - 1][j - nums[i]];
                }
                dp[i][j] = pick + notPick;
            }
        }

        return dp[n - 1][diff];
    }
};