#include <iostream>
#include <vector>
using namespace std;

int util(int idx, vector<int> heights, int n, vector<int> &dp)
{
    if (idx >= n)
        return 1e9;
    if (idx == n - 1)
        return 0;
    if (dp[idx] != -1)
        return dp[idx];

    int right = 1e9;

    int left = util(idx + 1, heights, n, dp) + abs(heights[idx + 1] - heights[idx]);

    if (idx + 2 <= n - 1)
        right = util(idx + 2, heights, n, dp) + abs(heights[idx + 2] - heights[idx]);

    // cout << idx << "-> " << left << " " << right << endl;

    return dp[idx] = min(left, right);
}

int main()
{
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; i++)
        cin >> heights[i];
    vector<int> dp(n + 1, -1);
    int ans = util(0, heights, n, dp);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int fs = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int ss = 2147483647;
        if (i > 1)
            ss = dp[i - 2] + abs(heights[i] - heights[i - 2]);
        dp[i] = min(fs, ss);
    }
    cout << dp[n - 1];
}