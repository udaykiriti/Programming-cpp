#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(0);
  int m, s, t; cin >> m >> s;
  string a, b;

  if (s == 0)
  {
    cout << (m == 1 ? "0 0" : "-1 -1") << endl;
    return 0;
  }

  FOR(i, 0, m)
  {
    t = min(s, 9);
    b += t + '0';
    s -= t;
  }

  if (s > 0)
  {
    cout << "-1 -1" << endl;
    return 0;
  }

  for (int i = m - 1; i >= 0; i--)
    a += b[i];

  int i = 0;
  while (i < m && a[i] == '0')
    i++;
  if (i < m)
    a[i]--;
    a[0]++;

  cout << a << " " << b << endl;
  return 0;
}
