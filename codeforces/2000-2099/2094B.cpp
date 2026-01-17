#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve(){
  int n,m,l,r;
  cin >> n >> m >> l >> r;
  if(m <= r) {
    cout << 0 << ' '<< m << endl;
  }
  else {
    int x = m - r;
    cout << -x << ' ' << r << endl;
  }
}

int main (int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
