#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
    ll a, b; cin >> a >> b;
    cout << min(min(a,b),(a+b)/4) << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int t(1),tcase(0); cin>>t;
  while(++tcase,t--) solve();
  return 0; 
}