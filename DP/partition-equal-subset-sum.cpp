class Solution
{
private:
    bool solve(int ind, int target, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (target == 0)
            return true;
        if (ind == 0)
            return nums[0] == target;

        if (dp[ind][target] != -1)
            return dp[ind][target];

        int pick = false;
        int notPick = solve(ind - 1, target, nums, dp);

        if (nums[ind] <= target)
            pick = solve(ind - 1, target - nums[ind], nums, dp);

        return dp[ind][target] = pick || notPick;
    }

public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0, n = nums.size();
        for (int i = 0; i < n; i++)
            sum += nums[i];
        if (sum % 2 == 1)
            return false;
        sum = sum / 2;
        // vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        // return solve(n-1, sum, nums,dp);

        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
        if (nums[0] <= sum)
            dp[0][nums[0]] = true;
        for (int i = 0; i < n; i++)
            dp[i][0] = true;

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                bool pick = false;
                bool notPick = dp[i - 1][j];

                if (nums[i] <= j)
                {
                    pick = dp[i - 1][j - nums[i]];
                }

                dp[i][j] = pick || notPick;
            }
        }
        return dp[n - 1][sum];
    }
};