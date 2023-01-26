class Solution
{
private:
    void util(int idx, int n, vector<int> &candidates, int target, vector<int> &ds, int currSum, vector<vector<int>> &ans)
    {

        if (currSum == target)
        {
            ans.push_back(ds);
            return;
        }

        for (int i = idx; i < n; i++)
        {
            if (i > idx && candidates[i] == candidates[i - 1])
                continue;
            if (candidates[i] + currSum > target)
                break;

            ds.push_back(candidates[i]);
            currSum += candidates[i];
            util(i + 1, n, candidates, target, ds, currSum, ans);
            ds.pop_back();
            currSum -= candidates[i];
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        int idx = 0;
        int n = candidates.size();
        vector<int> ds;
        int currSum = 0;
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        util(idx, n, candidates, target, ds, currSum, ans);

        return ans;
    }
};