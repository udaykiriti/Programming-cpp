#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FastIO()                    \
  ios_base::sync_with_stdio(false); \
  cin.tie(nullptr);                 \
  cout.tie(nullptr);
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)

void solve()
{
  int n; cin >> n;
  int best = -1, winner = -1;
  FOR(i, 1, n)
  {
    int a, b; cin >> a >> b;
    if (a <= 10 && b > best)
    {
      best = b;
      winner = i;
    }
  }
  cout << winner << endl;
}

int main()
{
  FastIO();
  int t; cin >> t;
  while (t--) solve();  
  return 0;
}