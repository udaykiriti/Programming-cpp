#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int n; cin >> n;
  vector<int> result;
  int place = 1;
  while (n > 0)
  {
    int digit = n % 10;
    if (digit != 0)
      result.push_back(digit * place);
    n /= 10; place *= 10;
  }

  cout << result.size() << "\n";
  for (int num : result)
    cout << num << " ";
  cout << "\n";
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(NULL);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}