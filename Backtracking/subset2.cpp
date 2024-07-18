class Solution
{
public:
    void solve(vector<int> &nums, vector<vector<int>> &ans, vector<int> &output, int i)
    {
        ans.push_back(output); // Add the current subset to the answer

        for (int j = i; j < nums.size(); j++)
        {
            if (j != i && nums[j] == nums[j - 1])
            {
                continue; // Skip duplicates
            }
            output.push_back(nums[j]);       // Include the current element
            solve(nums, ans, output, j + 1); // Recurse with the next index
            output.pop_back();               // Backtrack by removing the last added element
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> output;
        sort(nums.begin(), nums.end());
        solve(nums, ans, output, 0);
        return ans;
    }
};
