#include <bits/stdc++.h>
using namespace std;
#define ln "\n"
#define stop_sync ios::sync_with_stdio(false)
#define untie_ios cin.tie(nullptr)
#define FOR(i, a, b) for (long i = (a); i < (b); i++)
#define BYE return 0;
void solve()
{
  long n; cin >> n;
  map<long, vector<char>> mv;
  vector<char> res(n, ' ');
  char nxt = 'a';

  FOR(p, 0, n)
  {
    int x; cin >> x;
    char cur;
    if (x == 0)
    {
      cur = nxt;
      ++nxt;
    }
    else
    {
      cur = mv[x - 1].back();
      mv[x - 1].pop_back();
    }
    cout << cur;
    mv[x].push_back(cur);
  }

  cout << ln;
}

int main()
{
  stop_sync; untie_ios;
  int t; cin>>t;
  while(t--) solve();
}