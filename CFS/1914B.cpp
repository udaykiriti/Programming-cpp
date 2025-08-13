#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(NULL);
#define testcases \
  int t;          \
  cin >> t;       \
  while (t--)
#define FOR(i, a, b) for (long i = (a); i <= (b); ++i)
#define RFOR(i, a, b) for (long i = (a); i > (b); --i)
#define endl '\n'

void solve(){
    long n, k; cin >> n >> k;
    FOR(p, 1, k)
      cout << p << " ";
    RFOR(p, n, k)
      cout << p << " ";
    cout << endl;
}

int main()
{
  fastio;
  int t; cin>>t;
  while(t--) solve();
  return 0;
}