#include<bits/stdc++.h>
using namespace std;
void fun(int* &p)
{
    p = NULL;
}
int main()
{
 int n = 10;
 int * x = &n;
 fun(x);
 cout << x << endl;

  return 0;
}