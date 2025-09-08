#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define FOR(i, a, b) for (int i = a; i < b; i++)

void solve(void){
  int a, b, n, x; cin>>a>>b>>n;
  int sum = b;
  FOR(i, 0, n){
    cin>>x;
    sum += min(x, a - 1);
  } cout << sum << endl;
}

int32_t main(int argc , char *argv[]){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t; cin>>t;
  while (t--) solve();
  return 0;
}
