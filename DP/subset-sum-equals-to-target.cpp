class Solution
{
private:
    bool solve(int ind, vector<int> arr, int sum, vector<vector<int>> &dp)
    {

        if (sum == 0)
            return true;
        if (ind == 0)
            return sum == arr[0];

        if (dp[ind][sum] != -1)
            return dp[ind][sum];

        bool notPick = solve(ind - 1, arr, sum, dp);
        bool pick = false;

        if (arr[ind] <= sum)
        {
            pick = solve(ind - 1, arr, sum - arr[ind], dp);
        }

        return dp[ind][sum] = pick || notPick;
    }

public:
    bool isSubsetSum(vector<int> arr, int sum)
    {
        // code here
        int n = arr.size();
        // vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        // return solve(n-1, arr, sum,dp);
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
        for (int i = 0; i < n; i++)
            dp[i][0] = true;
        if (arr[0] <= sum)
            dp[0][arr[0]] = true;

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {

                bool pick = false;
                bool notPick = dp[i - 1][j];

                if (arr[i] <= j)
                    pick = dp[i - 1][j - arr[i]];

                dp[i][j] = pick || notPick;
            }
        }
        return dp[n - 1][sum];
    }
};