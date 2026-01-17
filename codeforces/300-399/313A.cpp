#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(x) cout<<(x)<<endl

void solve()
{
  int n; cin >> n;
  if (n >= 0)
  {
    cout << n << endl;
  }
  else
  {
    int r1 = n / 10;
    int r2 = (n / 100) * 10 + n % 10;
    cout << max(r1, r2) << endl;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  solve();
  return 0;
}
