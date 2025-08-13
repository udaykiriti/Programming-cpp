#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define BYE return 0
#define ll long long
ll ara[100005];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  ll t, n, m, i, sum, p, ans;
  string s; cin >> t;
  while (t--)
  {
    sum = 0;
    p = 0;
    cin >> n >> m;
    for (i = 1; i <= n; i++)
    {
      cin >> s;
      if (p == 1)
        continue;
      sum += s.size();
      if (sum > m)
      {
        p = 1;
        ans = i - 1;
      }
    }
    if (p == 0)
      cout << n << "\n";
    else
      cout << ans << "\n";
  } 
  BYE;
}