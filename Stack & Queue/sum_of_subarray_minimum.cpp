class Solution
{
public:
    vector<int> pse(vector<int> &A)
    {
        int n = A.size();
        vector<int> ans(n);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && A[st.top()] >= A[i])
            {
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> nse(vector<int> &A)
    {
        int n = A.size();
        stack<int> st;
        vector<int> ans(A.size());
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && A[st.top()] > A[i])
            {
                st.pop();
            }
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int> &arr)
    {
        long long mod = 1e9 + 7;
        int n = arr.size();
        long long total = 0;
        vector<int> prev = pse(arr);
        vector<int> next = nse(arr);
        for (int i = 0; i < n; i++)
        {
            int left = i - prev[i];
            int right = next[i] - i;
            total = (total + (right * left * 1LL * arr[i]) % mod) % mod;
        }
        return total;
    }
};