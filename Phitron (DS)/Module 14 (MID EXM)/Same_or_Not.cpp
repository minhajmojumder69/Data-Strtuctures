#include <bits/stdc++.h>
using namespace std;
int main()
{
    stack<int> st;
    queue<int> q;
    int x, n;
    cin >> x >> n;
    for (int i = 0; i < x; i++)
    {
        int val;
        cin >> val;
        st.push(val);
    }
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        q.push(val);
    }
    if (x != n)
    {
        cout << "NO";
        return 0;
    }
    else
    {
        int flag = 0;
        while (!st.empty())
        {
            if (st.top() == q.front())
            {
                flag = 1;
                st.pop();
                q.pop();
            }
            else
            {
                cout << "NO";
                return 0;
            }
        }
        if (flag == 1)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
    }
    return 0;
}
