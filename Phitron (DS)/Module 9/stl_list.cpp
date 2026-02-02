#include<bits/stdc++.h>
using namespace std;
int main()
{
    list<int> ar(10,3);

    // for (auto it = ar.begin(); it!= ar.end() ; it++)
    // {
    //     cout << *it << " ";
    // }

    for(int val : ar )
    {
        cout << val << " ";
    }
    
  return 0;
}