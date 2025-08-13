#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve()
{
  int n; cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) cin >> nums[i];
  int max_val = *max_element(nums.begin(), nums.end());
  int min_val = *min_element(nums.begin(), nums.end());
  cout << (max_val - min_val) << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}