#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define ln "\n"
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define rFOR(i, a, b) for (int i = (a); i >= (b); i--)
#define all(x) (x).begin(), (x).end()

void solve()
{
  i64 n; cin>>n;
  vector<i64> a(n);
  FOR(i, 0, n) cin>>a[i];
  bool possible = true;
  i64 first = a[0], count_first = 1, second = 0, count_second = 0;

  FOR(i, 1, n)
  {
    if (a[i] == first)
    {
      count_first++;
    }
    else if (count_second == 0)
    {
      second = a[i];
      count_second = 1;
    }
    else if (a[i] == second)
    {
      count_second++;
    }
    else
    {
      possible = false;
    }
  }
  if (count_second > 0)
    if (count_first > count_second + 1 || count_second > count_first + 1) 
      possible = false;
  cout << (possible ? "Yes" : "No") << ln;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t; cin>>t;
  while(t--) solve();
  return 0;
}