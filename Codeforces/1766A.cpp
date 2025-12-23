#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve()
{
  int n; cin >> n;
  int count = 0;
  for (int digit = 1; digit <= 9; ++digit)
  {
    int num = digit;

    while (num <= n)
    {
      ++count;
      num *= 10;
    }
  }
  cout << count << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t; cin >> t;
  while (t--)
    solve();
  return 0;
}