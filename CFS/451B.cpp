#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(x) cout<<(x)<<endl
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define SORT(x) sort((x).begin(),(x).end())

void solve()
{
  int n; cin >> n;
  vector<int> a(n), b(n);
  FOR (i,0,n)
  {
    cin >> a[i];
    b[i] = a[i];
  }
 SORT(b);
  int l = 0, r = n - 1;
  while (l < n && a[l] == b[l])
    ++l;
  while (r >= 0 && a[r] == b[r])
    --r;

  if (l >= r)
  {
    cout << "yes\n"<< 1 << ' ' << 1 << '\n';
    return;
  }

  reverse(a.begin() + l, a.begin() + r + 1);

  if (a == b)
    cout << "yes\n"<< l + 1 << ' ' << r + 1 << '\n';
  else
    cout << "no\n";
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  solve();
  return 0;
}