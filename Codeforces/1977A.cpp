#include <bits/stdc++.h>
using namespace std;
#define stop_sync ios::sync_with_stdio(false)
#define untie_ios cin.tie(nullptr)
#define endl "\n"

void solve()
{
  int n, m; cin >> n >> m;
  if (m <= n && (n - m) % 2 == 0) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}

int main()
{
  stop_sync; untie_ios;
  int t; cin>>t;
  while(t--) solve();
  return 0;
}