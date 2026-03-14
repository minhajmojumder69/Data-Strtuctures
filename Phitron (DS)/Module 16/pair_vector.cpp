#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    cin >> x;
    vector<pair<int,int>> v(x);
    for (int i = 0; i < x; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    for (int i = 0; i < x; i++)
    {
        cout << v[i].first << " " << v[i].second << endl;
    }
 
  return 0;
}