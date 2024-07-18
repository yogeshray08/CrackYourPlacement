class Solution
{
public:
    void solve(int idx, int n, int k, vector<vector<int>> &ans, vector<int> output)
    {
        if (output.size() == k)
        {
            ans.push_back(output);
            return;
        }

        for (int i = idx; i < n; i++)
        {
            output.push_back(i + 1);
            solve(i + 1, n, k, ans, output);
            output.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        vector<int> output;
        solve(0, n, k, ans, output);
        return ans;
    }
};