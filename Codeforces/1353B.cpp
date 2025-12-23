#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FOR(i,a,b) for(int i=a;i<b;i++)

void solve()
{
  int n, k; cin >> n >> k;
  vector<int> a(n), b(n);
  FOR (i,0,n) cin >> a[i];
  FOR (i, 0, n) cin >> b[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end(), greater<>());
  FOR (i,0,k)
    if (a[i] < b[i])
      swap(a[i], b[i]);
    else
      break;
  int sum = 0;
  for (int num : a)
    sum += num;
  cout << sum << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}