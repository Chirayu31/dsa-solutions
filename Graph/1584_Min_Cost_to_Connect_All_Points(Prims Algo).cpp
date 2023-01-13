class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

        map<pair<int, int>, int> mp;

        for (auto point : points)
        {
            mp[{point[0], point[1]}] = 0;
        }

        int ans = 0;

        pq.push({0, {points[0][0], points[0][1]}});

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int wt = it.first;
            int x1 = it.second.first, y1 = it.second.second;

            if (mp[{x1, y1}] == 1)
                continue;

            mp[{x1, y1}] = 1;
            ans += wt;

            for (auto point : points)
            {
                int x2 = point[0], y2 = point[1];
                if (mp[{x2, y2}] == 0)
                {
                    int d = abs(x2 - x1) + abs(y2 - y1);
                    pq.push({d, {x2, y2}});
                }
            }
        }
        return ans;
    }
};