#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FastIO()                    \
  ios_base::sync_with_stdio(false); \
  cin.tie(nullptr);                 \
  cout.tie(nullptr);
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORk(i, a, b, k) for (int i = (a); i <= (b); i += (k))
#define RFOR(i, a, b) for (int i = (a); i >= (b); i--)
#define RFORK(i, a, b, k) for (int i = (a); i >= (b); i -= (k))

void solve()
{
  int k; cin >> k;
  vector<int> a(12);
  FOR(i, 0, 11)
    cin >> a[i];

  sort(a.rbegin(), a.rend());

  int sum = 0, months = 0;
  for (int i = 0; i < 12 && sum < k; ++i)
  {
    sum += a[i];
    months++;
  }

  if (sum >= k)
    cout << months << endl;
  else
    cout << -1 << endl;
}

int main()
{
  FastIO();
  solve();
  return 0;
}