#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

void solve()
{
  ll k; cin>>k;
  if (k % 2)
    cout<<"YES"<<endl;
  else
    cout<<"NO"<<endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  long t; cin>>t;
  while (t--) solve();
  return 0;
}