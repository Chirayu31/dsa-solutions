class DisjointSet
{
    vector<int> parent, size;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
        {
            return node;
        }

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        vector<pair<int, pair<int, int>>> v;
        int n = points.size();

        for (int i = 0; i < n; i++)
        {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = i + 1; j < n; j++)
            {
                int x2 = points[j][0];
                int y2 = points[j][1];
                int d = abs(x2 - x1) + abs(y2 - y1);
                v.push_back({d, {i, j}});
            }
        }
        DisjointSet ds(n);
        int totWt = 0;

        sort(v.begin(), v.end());

        for (auto it : v)
        {
            if (ds.findUPar(it.second.first) != ds.findUPar(it.second.second))
            {
                totWt += it.first;
                ds.unionBySize(it.second.first, it.second.second);
            }
        }
        return totWt;
    }
};