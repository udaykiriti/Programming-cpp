#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(x) cout<<(x)<<endl

void solve()
{
  int n, x, count1 = 0, count2 = 0; cin >> n;
  while (n--)
  {
    cin >> x;
    if (x == 1) count1++;
    else count2++;
  }
  if ((count2 % 2 == 0 && count1 % 2 == 0) || (count2 % 2 != 0 && count1 % 2 == 0 && count1 > 0))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int t; cin >> t;
  while (t--)
    solve();
  return 0;
}