#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(x) cout<<(x)<<endl
#define FOR(i,a,b) for(int i=a;i<b;i++)

void solve()
{
  int n; string s; cin >> n >> s;
  FOR ( i, 1, n)
  {
    if (s[i] != s[0])
    {
      cout << "YES"<<endl;
      return;
    }
  }
  cout << "NO"<<endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(NULL);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}