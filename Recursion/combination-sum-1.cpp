class Solution
{

private:
    void cs(int idx, int n, int target, vector<int> &candidates, vector<int> &ds, vector<vector<int>> &ans, int currSum)
    {

        if (idx >= n)
        {
            if (currSum == target)
            {
                ans.push_back(ds);
            }
            return;
        }

        if (candidates[idx] + currSum <= target)
        {
            ds.push_back(candidates[idx]);
            currSum += candidates[idx];
            cs(idx, n, target, candidates, ds, ans, currSum);
            ds.pop_back();
            currSum -= candidates[idx];
        }
        cs(idx + 1, n, target, candidates, ds, ans, currSum);
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> ds;
        int idx = 0, n = candidates.size();

        vector<vector<int>> ans;
        cs(idx, n, target, candidates, ds, ans, 0);
        return ans;
    }
};