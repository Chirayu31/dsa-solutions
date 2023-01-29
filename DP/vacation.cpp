// atcoder
#include <iostream>
#include <vector>
using namespace std;

int solve(int idx, int last, vector<vector<int>> activities, vector<vector<int>> &dp)
{
    if (idx == 0)
    {
        int maxi = -1;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
            {
                maxi = max(activities[0][i], maxi);
            }
        }
        return maxi;
    }

    if (dp[idx][last] != -1)
    {
        return dp[idx][last];
    }

    int maxi = -1;

    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {
            int points = activities[idx][i] + solve(idx - 1, i, activities, dp);
            maxi = max(maxi, points);
        }
    }
    return dp[idx][last] = maxi;
}

int tab(vector<vector<int>> activities, vector<vector<int>> &dp)
{
    int n = activities.size();

    for (int last = 0; last < 4; last++)
    {
        int maxi = -1;
        for (int i = 0; i < 3; i++)
        {

            if (i != last)
            {
                maxi = max(maxi, activities[0][i]);
            }
        }
        dp[0][last] = maxi;
        // cout << dp[0][last] << " ";
    }

    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            int maxi = -1;
            for (int i = 0; i < 3; i++)
            {
                if (i != last)
                {
                    maxi = max(maxi, activities[day][i] + dp[day - 1][i]);
                }
            }
            dp[day][last] = maxi;
        }
    }

    return dp[n - 1][3];
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> activities(n, vector<int>(3, 0));
    vector<vector<int>> dp(n, vector<int>(4, -1));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> activities[i][j];
        }
    }
    cout << tab(activities, dp);
    // cout << solve(n - 1, 3, activities, dp);
}