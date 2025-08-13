// Problem: C. Minimum Varied Number
// Contest: Codeforces Round 811 (Div. 3) - Problem 1714C
// LINK: https://codeforces.com/contest/1714/problem/C

#include <bits/stdc++.h>
using namespace std;

#define fast_io                \
  ios::sync_with_stdio(false); \
  cin.tie(nullptr);            \
  cout.tie(nullptr)
#define int long long
#define endl '\n'
#define EXIT return 0

void solve()
{
  int s; cin >> s;
  string str = "";
  for (int i = 9; i >= 1; i--)
  {
    if (s >= i)
    {
      str = char(i + '0') + str;
      s -= i;
    }
  }
  cout << str << endl;
}

int32_t main()
{
  fast_io;
  int t; cin >> t;
  while (t--) solve();
  EXIT;
}
