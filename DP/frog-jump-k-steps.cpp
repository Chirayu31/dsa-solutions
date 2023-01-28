#include <iostream>
#include <vector>
using namespace std;

int util(vector<int> heights, int n, vector<int> &dp, int k)
{
    if (n == 0)
        return 0;

    if (dp[n] != -1)
        return dp[n];

    int ans = INT_MAX;

    for (int i = 1; i <= k; i++)
    {
        if (n - i >= 0)
        {
            int temp = util(heights, n - i, dp, k) + abs(heights[n] - heights[n - i]);
            ans = min(temp, ans);
        }
    }

    return dp[n] = ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> heights(n);
    for (int i = 0; i < n; i++)
        cin >> heights[i];

    vector<int> dp(n + 1, 1e9);
    // int ans = util(heights, n - 1, dp, k);
    // cout << ans;
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                dp[i] = min(dp[i], dp[i - j] + abs(heights[i] - heights[i - j]));
            }
        }
    }
    cout << dp[n - 1];
}