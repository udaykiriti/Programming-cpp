#include <bits/stdc++.h>
using namespace std;
#define ln "\n"
#define fast_io                \
  ios::sync_with_stdio(false); \
  cin.tie(nullptr)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

void solve()
{
  long n; cin>>n;
  vector<long> a(n);
  FOR(i, 0, n) cin>>a[i];
  sort(a.rbegin(), a.rend());
  if (a[0] == a.back())
  {
    cout<<"NO"<<ln;
    return;
  }
  cout<<"YES"<<ln; cout<<a.back()<<ln;
  FOR(i, 0, n - 1)
      cout << a[i] << " ";
  cout << ln;
}

int main()
{
  fast_io;
  int t; cin>>t;
  while(t--) solve();
  return 0;
}