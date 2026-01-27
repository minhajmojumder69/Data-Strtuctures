#include <bits/stdc++.h>
using namespace std;
void prefix_sum(vector<long long int> &pre,int i,int n)
{
    if (i>n)
    {
        return;
    }
    prefix_sum(pre,i+1,n);
    cout << pre[i] << " ";
}
int main()
{
    int n;
    cin >> n;
    vector<long long int> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    vector<long long int> pre(n + 1);
    pre[1] = v[1];
    for (int i = 2; i <= n; i++)
    {
        pre[i] = pre[i - 1] + v[i];
    }

    prefix_sum(pre,1,n);

    return 0;
}
