class Solution
{
public:
    vector<int> NSE(vector<int> &nums)
    {
        stack<int> st;
        int n = nums.size();
        vector<int> nse(n, -1);
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && nums[st.top()] >= nums[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                nse[i] = n;
            }
            else
            {
                nse[i] = st.top();
            }
            st.push(i);
        }
        return nse;
    }
    vector<int> PSE(vector<int> &nums)
    {
        stack<int> st;
        int n = nums.size();
        vector<int> pse(n, 0);
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && nums[st.top()] >= nums[i])
                st.pop();
            if (st.empty())
                pse[i] = -1;
            else
                pse[i] = st.top();
            st.push(i);
        }
        return pse;
    }
    int largestRectangleArea(vector<int> &h)
    {
        vector<int> nse = NSE(h);
        vector<int> pse = PSE(h);

        int maxArea = 0;

        for (int i = 0; i < h.size(); i++)
        {
            int width = nse[i] - pse[i] - 1;
            int area = h[i] * width;
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};