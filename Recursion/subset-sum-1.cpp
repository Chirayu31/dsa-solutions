class Solution
{

private:
    void util(vector<int> arr, int n, int sum, int idx, vector<int> &ans)
    {
        if (idx >= n)
        {
            ans.push_back(sum);
            return;
        }

        util(arr, n, sum + arr[idx], idx + 1, ans);
        util(arr, n, sum, idx + 1, ans);
    }

public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ans;
        util(arr, N, 0, 0, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};