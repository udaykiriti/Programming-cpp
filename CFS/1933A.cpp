#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int t; cin >> t;
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    int totalSum = 0;
    for (int i = 0; i < n; ++i)totalSum += a[i];
    int maxSum = totalSum;
    int currentNegateGain = 0;
    for (int i = 0; i < n; ++i)
    {
      if (a[i] < 0)
        currentNegateGain += -2 * a[i];
      else
        break;
      maxSum = max(maxSum, totalSum + currentNegateGain);
    }
    cout << maxSum << "\n";
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(NULL);
  int t; cin>>t;
  while(t--) solve();
  return 0;
}