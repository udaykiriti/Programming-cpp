#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; cin >> n;
    vector<ll> v(n);
    ll sum = 0;
    for (auto &i : v){
      cin >> i;
      sum += i;
    }
    ll avg = sum / n;
    for (int i = n - 1; i > 0; i--){
      if (v[i] < avg) {
        v[i - 1] -= (avg - v[i]);
        v[i] = avg;
      }
    }
    bool ok = true;
    for (int i = 0; i < n; i++)
      ok &= (v[i] == avg);
    cout << (ok ? "YES" : "NO") << '\n';
    
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
