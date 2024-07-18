class Solution
{
public:
    void solve(vector<int> &nums, vector<vector<int>> &ans, vector<int> output, int i, int n)
    {
        if (i == n)
        {
            ans.push_back(output);
            return;
        }

        // exclude
        solve(nums, ans, output, i + 1, nums.size());
        // include
        int element = nums[i];
        output.push_back(element);
        solve(nums, ans, output, i + 1, nums.size());
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> output;
        solve(nums, ans, output, 0, nums.size());
        return ans;
    }
};