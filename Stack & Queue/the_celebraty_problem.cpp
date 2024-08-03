class Solution
{
public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &m, int n)
    {
        int top = 0;
        int down = n - 1;
        while (top < down)
        {
            if (m[top][down] == 1)
                top++;
            else if (m[down][top] == 1)
                down--;
            else
            {
                top++;
                down--;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (top == i || (m[top][i] == 0 && m[i][top] == 1))
                continue;
            else
                return -1;
        }
        return top;
    }
};