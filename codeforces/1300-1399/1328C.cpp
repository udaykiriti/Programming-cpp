#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pb push_back
#define FastIO                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);                  \
  cout.tie(0);
#define endl '\n'
void solve()
{
  int n; cin >> n;
  string s; cin >> s;
  string a = "", b = "";
  bool flag = false;

  for (int i = 0; i < n; ++i)
  {
    if (!flag)
    {
      if (s[i] == '2')
      {
        a.pb('1');
        b.pb('1');
      }
      else if (s[i] == '1')
      {
        a.pb('1');
        b.pb('0');
        flag = true;
      }
      else
      {
        a.pb('0');
        b.pb('0');
      }
    }
    else
    {
      a.pb('0');
      b.pb(s[i]);
    }
  }
  cout << a <<endl<< b;
}

int32_t main()
{
  FastIO;
  int t; cin >> t;
  while (t--)
  {
    solve();
    cout << endl;
  }
  return 0;
}