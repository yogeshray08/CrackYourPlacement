class Solution
{
public:
    void solve(int i, int target, vector<int> &nums, vector<int> &output, vector<vector<int>> &ans)
    {
        if (target == 0)
        {
            ans.push_back(output);
            return;
        }

        for (int j = i; j < nums.size(); j++)
        {
            if (nums[j] <= target)
            {
                output.push_back(nums[j]);
                solve(j, target - nums[j], nums, output, ans);
                output.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int> &nums, int target)
    {
        vector<int> output;
        vector<vector<int>> ans;
        solve(0, target, nums, output, ans);
        return ans;
    }
};