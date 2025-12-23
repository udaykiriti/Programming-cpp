#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int n, k; cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  sort(a.begin(), a.end());

  if (k == 0)
  {
    if (a[0] > 1)
      cout << a[0] - 1 << endl;
    else
      cout << -1 << endl;
  }
  else if (k == n || a[k - 1] != a[k])
  {
    cout << a[k - 1] << endl;
  }
  {
    cout << -1 << endl;
  }
  return 0;
}