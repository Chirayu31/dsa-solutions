class Solution
{
public:
    int minimumDifference(vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += nums[i];

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

        int diff = 1e9;

        for (int s1 = 0; s1 <= sum; s1++)
        {
            if (dp[n - 1][s1] == true)
                diff = min(diff, abs(s1 - (sum - s1)));
        }

        return dp[n - 1][sum];
    }
};