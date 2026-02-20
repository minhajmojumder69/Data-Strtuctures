#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        string s;
        cin >> s;
        stack<char> st;
        for (char c : s)
        {
            if (!st.empty())
            {
                if (st.top() != c)
                {
                    st.pop();
                }
                else
                {
                    st.push(c);
                }
            }
            else
            {
                st.push(c);
            }
        }
        if (st.empty())
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }

    }
}