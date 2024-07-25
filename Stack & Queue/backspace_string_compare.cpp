class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        stack<char> s1, t1;
        int sn = s.size();
        int tn = t.size();
        int i = 0;
        while (i < sn)
        {
            char a = s[i++];
            if (a != '#')
                s1.push(a);
            else
            {
                if (!s1.empty())
                    s1.pop();
            }
        }
        i = 0;
        while (i < tn)
        {
            char a = t[i++];
            if (a != '#')
                t1.push(a);
            else
            {
                if (!t1.empty())
                    t1.pop();
            }
        }
        if (s1 == t1)
            return true;
        return false;
    }
};