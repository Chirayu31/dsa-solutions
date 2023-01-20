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
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int maxNode = -1;

        for (int i = 0; i < edges.size(); i++)
        {
            maxNode = max(maxNode, edges[i][0]);
            maxNode = max(maxNode, edges[i][1]);
        }

        DisjointSet ds(maxNode + 1);
        vector<int> res;
        for (int i = 0; i < edges.size(); i++)
        {
            if (ds.findUPar(edges[i][0]) == ds.findUPar(edges[i][1]))
            {
                res.push_back(edges[i][0]);
                res.push_back(edges[i][1]);
            }
            else
            {
                ds.unionBySize(edges[i][0], edges[i][1]);
            }
        }
        return res;
    }
};
