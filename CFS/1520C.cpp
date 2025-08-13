#include <bits/stdc++.h>
using namespace std;
#define FastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int main()
{
  FastIO; int t; cin >> t;
  while (t--)
  {
    int n; cin >> n;
    if (n == 2)
      cout << -1 << endl;
    else
    {
      for (int i = 1; i <= n * n; i += 2) cout << i << ' ';
      for (int i = 2; i <= n * n; i += 2) cout << i << ' ';
      cout << endl;
    }
  }
}