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
  int n; cin >> n;
  vector<int> candies(n);
  for (int i = 0; i < n; i++)
    cin >> candies[i];
  sort(candies.rbegin(), candies.rend());
  int mihaiCandies = 0, biancaCandies = 0;

  for (int i = 0; i < n; i++)
  {
    if (candies[i] % 2 == 0)
      mihaiCandies += candies[i];
    else
      biancaCandies += candies[i];
  }

  if (mihaiCandies > biancaCandies)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}

int main()
{
  FastIO();
  int t; cin >> t;
  while (t--) solve();
  return 0;
}