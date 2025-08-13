#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < n; i++)
      cin >> b[i];

    vector<int> d(n + 1, 0), e(n + 1, 0);

    d[n] = 0;
    e[n] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
      int c = (a[i] == b[i]) ? 1 : 0;
      d[i] = d[i + 1] + c;
      e[i] = d[i + 1];
      e[i] = max(e[i], e[i + 1] + c);
    }

    cout << max(d[0], e[0]) << "\n";
  }
  return 0;
}
