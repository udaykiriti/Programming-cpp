#include <bits/stdc++.h>
using namespace std;
#define ln "\n"

void solve()
{
  long n;  cin >> n;
  string s; cin >> s;
  long cnt = 1, cur = 1;
  for (long p = 1; p < s.size(); p++)
  {
    if (s[p] == s[p - 1])
      ++cur;
    else
      cur = 1;
    cnt = max(cnt, cur);
  }
  cout << cnt + 1 << ln;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t; cin>>t;
  while(t--) solve();
  return 0;
}