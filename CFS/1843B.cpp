#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(NULL);
  int t; cin >> t;
  while (t--)
  {
    int n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    ll sum = 0;
    int operations = 0;
    bool inNegative = false;

    for (int i = 0; i < n; ++i)
    {
      sum += abs(a[i]);

      if (a[i] < 0 && !inNegative)
      {
        inNegative = true;
        operations++;
      }
      else if (a[i] > 0)
      {
        inNegative = false;
      }
    }
    cout << sum << " " << operations << "\n";
  }
  return 0;
}