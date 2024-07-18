class Solution
{
public:
    void solve(int idx, int n, set<vector<int>> &ans, vector<int> &nums)
    {
        if (idx == n)
        {
            ans.insert(nums);
            return;
        }
        for (int i = idx; i < n; i++)
        {
            swap(nums[idx], nums[i]);
            solve(idx + 1, n, ans, nums);
            swap(nums[idx], nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> mainAns;
        set<vector<int>> ans;
        solve(0, n, ans, nums);
        for (auto a : ans)
        {
            mainAns.push_back(a);
        }
        return mainAns;
    }
};