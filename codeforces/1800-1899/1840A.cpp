#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define ln "\n"
#define EXIT return 0
#define PRINT(x) cout << x << ln

void solve()
{
  long n; cin >> n;
  string s; cin >> s;
  long idx = 0;
  while (idx < n)
  {
    char ch = s[idx];
    cout << ch;
    ++idx;
    while (idx < n && s[idx] != ch)
      ++idx;
    ++idx;
  }

  cout << ln;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t; cin>>t;
  while(t--) solve();
  EXIT;
}