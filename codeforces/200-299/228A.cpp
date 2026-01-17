#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve()
{
  int s1, s2, s3, s4; cin >> s1 >> s2 >> s3 >> s4;
  set<int> unique_colors = {s1, s2, s3, s4};
  cout << 4 - unique_colors.size() << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(NULL);
  solve();
  return 0;
}