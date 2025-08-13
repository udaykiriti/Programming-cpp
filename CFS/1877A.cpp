#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define EXIT return 0
#define FOR(i, a, b) for (int i = a; i < b; i++)

void fastIO()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
}

void solve()
{
  int n, freqSum = 0; cin >> n;
  FOR(i, 0, n - 1)
  {
    int freq; cin >> freq;
    freqSum += freq;
  }
  cout << freqSum * (-1) << endl;
}

int main()
{
  fastIO();
  int t; cin >> t;
  while (t--) solve();
  EXIT;
}