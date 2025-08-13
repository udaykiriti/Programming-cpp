#include <bits/stdc++.h>
using namespace std;

bool isPossible(const vector<int> &angles, int index = 0, int current_sum = 0)
{
  if (index == angles.size()) return current_sum % 360 == 0;
  return isPossible(angles, index + 1, current_sum + angles[index]) || isPossible(angles, index + 1, current_sum - angles[index]);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int n; cin >> n;
  vector<int> angles(n);
  for (int i = 0; i < n; ++i) cin >> angles[i];
  if (isPossible(angles)) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}