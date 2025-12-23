#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)

void solve()
{
  int a, b, c; cin >> a >> b >> c;
  vector<int> nums = {a, b, c};
  sort(nums.begin(), nums.end());
  FOR(i, 0, 4)
  {
    nums[0]++;
    sort(nums.begin(), nums.end());
  }
  cout << nums[0] * nums[1] * nums[2] << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}