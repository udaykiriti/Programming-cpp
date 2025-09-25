#include <bits/stdc++.h>
#define int long long
#define vi vector<int>
#define FOR(i,a,b) for (int i = a; i < (b); ++i)
using namespace std;

void solve(){
  int n; cin >> n;
  vi a(n), b(n);
  FOR(i,0,n) cin >> a[i];
  FOR(i,0,n) cin >> b[i];

  int total_m = 0, total_s = 0;
  FOR(i, 0,n) {
    int gain = a[i];
    int penalty = (i + 1 < n) ? b[i + 1] : 0;
    if (gain > penalty){
      total_m += a[i];
      if (i + 1 < n) total_s += b[i + 1];
    }
  } cout << total_m - total_s << endl;
}

int32_t main(int argc , char *argv[]){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t; cin >> t;
  while (t--) solve();
}
