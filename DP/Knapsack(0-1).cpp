#include <bits/stdc++.h>
using namespace std;

class Solution
{

private:
    int solve(int ind, int wt[], int val[], int W, vector<vector<int>> &dp)
    {

        // base case
        if (ind == 0)
        {
            if (wt[ind] <= W)
                return val[ind];
            else
                return 0;
        }

        if (dp[ind][W] != -1)
            return dp[ind][W];

        int notPick = 0 + solve(ind - 1, wt, val, W, dp);
        int pick = INT_MIN;

        if (wt[ind] <= W)
        {
            pick = val[ind] + solve(ind - 1, wt, val, W - wt[ind], dp);
        }

        return dp[ind][W] = max(pick, notPick);
    }

public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n)
    {
        // Your code here
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        // return solve(n-1, wt, val, W, dp);
        for (int i = 0; i <= W; i++)
        {
            if (wt[0] <= i)
                dp[0][i] = val[0];
            else
                dp[0][i] = 0;
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= W; j++)
            {
                int notPick = 0 + dp[i - 1][j];
                int pick = INT_MIN;
                if (wt[i] <= j)
                {
                    pick = val[i] + dp[i - 1][j - wt[i]];
                }
                dp[i][j] = max(pick, notPick);
            }
        }
        return dp[n - 1][W];
    }
};
