class Solution
{
private:
    void dfs(string start, string end, map<string, int> &visited, map<string, vector<string>> adj, bool &found, double &val, map<string, double> mp_values)
    {
        visited[start] = 1;

        if (found == true)
        {
            return;
        }
        for (auto child : adj[start])
        {
            if (visited[child] != 1)
            {
                val *= mp_values[start + "->" + child];
                if (child == end)
                {
                    found = true;
                    return;
                }
                dfs(child, end, visited, adj, found, val, mp_values);
                if (found == true)
                    return;
                else
                    val /= mp_values[start + "->" + child];
            }
        }
    }

public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        map<string, vector<string>> adj;
        map<string, double> mp_values;
        vector<double> ans;

        for (int i = 0; i < equations.size(); i++)
        {
            string num = equations[i][0];
            string den = equations[i][1];
            mp_values[num + "->" + den] = values[i];
            mp_values[den + "->" + num] = 1 / values[i];
            adj[num].push_back(den);
            adj[den].push_back(num);
        }

        for (int i = 0; i < queries.size(); i++)
        {
            string start = queries[i][0];
            string end = queries[i][1];
            bool found = false;
            double val = 1;
            if (adj.find(start) == adj.end() || adj.find(end) == adj.end())
            {
                found = false;
            }
            else
            {
                map<string, int> visited;
                if (start == end)
                {
                    found = true;
                }
                else
                {
                    dfs(start, end, visited, adj, found, val, mp_values);
                }
            }
            if (found == true)
                ans.push_back(val);
            else
                ans.push_back(-1);
        }
        return ans;
    }
};