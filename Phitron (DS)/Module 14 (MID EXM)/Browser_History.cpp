#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<string> lst;
    string val;

    while (1)
    {
        cin >> val;
        if (val == "end")
        {
            break;
        }
        lst.push_back(val);
    }

    int q;
    cin >> q;

    auto tmp = lst.begin();

    for (int i = 0; i < q; i++)
    {
        string cmnd;
        cin >> cmnd;

        if (cmnd == "visit")
        {
            string web;
            cin >> web;

            auto it = find(lst.begin(), lst.end(), web);

            if (it != lst.end())
            {
                tmp = it;
                cout << *tmp << endl;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
        else if (cmnd == "next")
        {

            if (next(tmp) != lst.end())
            {
                tmp++;
                cout << *tmp << endl;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
        else if (cmnd == "prev")
        {
            if (tmp != lst.begin())
            {
                tmp--;
                cout << *tmp << endl;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
    }

    return 0;
}