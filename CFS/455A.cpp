#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(x) cout<<(x)<<endl

void solve()
{
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  vector<int> freq(100001, 0);
  for (int x : a)
    freq[x]++;

  vector<long long> dp(100001, 0);
  dp[1] = freq[1];

  for (int i = 2; i <= 100000; ++i)
    dp[i] = max(dp[i - 1], dp[i - 2] + 1LL * i * freq[i]);

  cout << dp[100000] << "\n";
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(NULL);
  solve();
  return 0;
}
