//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{

private:
    int solve(int ind, int W, int val[], int wt[], vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            return (W / wt[0]) * val[0];
        }

        if (dp[ind][W] != -1)
            return dp[ind][W];

        int notPick = solve(ind - 1, W, val, wt, dp);
        int pick = -1e9;
        if (wt[ind] <= W)
        {
            pick = solve(ind, W - wt[ind], val, wt, dp) + val[ind];
        }
        return dp[ind][W] = max(pick, notPick);
    }

public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        // vector<vector<int>> dp(N, vector<int>(W+1, -1));
        // return solve(N-1, W, val, wt, dp);

        vector<vector<int>> dp(N, vector<int>(W + 1, 0));

        for (int i = 0; i <= W; i++)
        {
            dp[0][i] = (i / wt[0]) * val[0];
        }

        for (int i = 1; i < N; i++)
        {
            for (int j = 0; j <= W; j++)
            {
                int notPick = dp[i - 1][j];
                int pick = -1e9;
                if (wt[i] <= j)
                {
                    pick = dp[i][j - wt[i]] + val[i];
                }
                dp[i][j] = max(pick, notPick);
            }
        }
        return dp[N - 1][W];
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, W;
        cin >> N >> W;
        int val[N], wt[N];
        for (int i = 0; i < N; i++)
            cin >> val[i];
        for (int i = 0; i < N; i++)
            cin >> wt[i];

        Solution ob;
        cout << ob.knapSack(N, W, val, wt) << endl;
    }
    return 0;
}
// } Driver Code Ends