#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(nullptr);
  int n; cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  ll totalSum = 0;
  for (int i = 0; i < n; ++i) totalSum += a[i];

  if (totalSum % 3 != 0)
  {
    cout << 0 << endl;
    return 0;
  }
  ll partSum = totalSum / 3;
  ll prefixSum = 0;
  ll ways = 0;
  ll countPartSum = 0;

  for (int i = 0; i < n - 1; ++i)
  {
    prefixSum += a[i];
    if (prefixSum == 2 * partSum) ways += countPartSum;
    if (prefixSum == partSum) countPartSum++;
  }
  cout << ways << endl;
  return 0;
}