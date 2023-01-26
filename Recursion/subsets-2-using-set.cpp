class Solution
{

private:
    set<vector<int>> s;
    void subset(int idx, int n, vector<int> &nums, vector<int> &ds)
    {
        if (idx >= n)
        {
            s.insert(ds);
            return;
        }
        ds.push_back(nums[idx]);
        subset(idx + 1, n, nums, ds);
        ds.pop_back();
        subset(idx + 1, n, nums, ds);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> ds;
        subset(0, n, nums, ds);
        vector<vector<int>> ans;
        for (auto it : s)
        {
            ans.push_back(it);
        }
        return ans;
    }
};