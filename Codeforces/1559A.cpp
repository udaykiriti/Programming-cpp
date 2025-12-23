#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define ln "\n"
#define stop_sync ios::sync_with_stdio(false)
#define untie_ios cin.tie(nullptr)
#define FOR(i, a, b) for (i64 i = (a); i < (b); i++)

void solve(void){
  i64 n; cin >> n;
  vector<i64> arr(n);
  FOR(i, 0, n) cin >> arr[i];
  i64 res = arr[0];
  FOR(i, 1, n) res &= arr[i];
  cout << res << ln;
}

int main(){
  stop_sync; untie_ios;
  int t; cin>>t;
  while(t--) solve();
  return 0;
}
