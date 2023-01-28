class Solution
{
private:
    int maxSum(int n, vector<int> &nums, vector<int> &dp)
    {
        if (n == 0)
            return nums[0];
        if (n < 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];

        int pick = maxSum(n - 2, nums, dp) + nums[n];
        int notPick = maxSum(n - 1, nums, dp);

        return dp[n] = max(pick, notPick);
    }

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, -1);
        // return maxSum(n-1, nums,dp);
        dp[0] = nums[0];

        for (int i = 1; i < n; i++)
        {
            int pick = nums[i];

            if (i - 2 >= 0)
            {
                // pick
                pick += dp[i - 2];
            }

            int notpick = dp[i - 1]; // not pick
            dp[i] = max(pick, notpick);
        }
        return dp[n - 1];
    }
};