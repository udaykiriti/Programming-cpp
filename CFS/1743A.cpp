#include <bits/stdc++.h>
using namespace std;
#define endl '\n';

int comb(int n, int k)
{
  if (k == 2) return n * (n - 1) / 2;
  return 0;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int t; cin >> t;
  while (t--)
  {
    int n; cin >> n;
    vector<int> unused(n);
    for (int i = 0; i < n; ++i) cin >> unused[i];
    int available_digits = 10 - n;
    if (available_digits < 2)
    {
      cout << 0 << endl;
    }
    else
    {
      int ways_to_choose_2_digits = comb(available_digits, 2);
      cout << ways_to_choose_2_digits * 6 << endl;
    }
  }
  return 0;
}