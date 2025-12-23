#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve()
{
  int n; cin >> n;
  if (n == 0)
  {
    cout << 1 << endl;
    return;
  }
  int cycle[] = {8, 4, 2, 6};
  cout << cycle[(n - 1) % 4] << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  solve();
  return 0;
}