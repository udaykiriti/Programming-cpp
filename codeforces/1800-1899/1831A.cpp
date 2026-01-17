#include <bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
#define FOR(i, a, b) for (int i = a; i <= b; i++)

void solve(){
  ll n; cin>>n;
  FOR(i, 1, n) {
    ll temp; cin>>(temp);
    cout << (n + 1) - temp << " ";
  }  cout << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  ll T; cin>>(T);
  while (T--) solve();
  return 0;
}
