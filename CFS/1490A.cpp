#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve()
{
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  int insertions = 0;
  for (int i = 0; i < n - 1; ++i) {
    int x = a[i];
    int y = a[i + 1];
    int small = min(x, y);
    int large = max(x, y);
    while (large > 2 * small)
    {
      small *= 2;
      ++insertions;
    }
  }
  cout << insertions << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}
