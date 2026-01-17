#include <bits/stdc++.h>
using namespace std;
#define ln "\n"
#define FOR(i, a, b) for (long i = (a); i < (b); i++)

void solve(){
  const int N = 8;
  vector<string> v(N);
  FOR(p, 0, N)
    cin >> v[p];

  char ans = '.';
  FOR(row, 0, N){
    if (ans != '.')
      break;
    bool test = true;
    FOR(col, 0, N){
      if (v[row][col] != 'R'){
        test = false;
        break;
      }
    }
    if (test) ans = 'R';
  }

  FOR(col, 0, N){
    if (ans != '.')
      break;
    bool test = true;
    FOR(row, 0, N){
      if (v[row][col] != 'B'){
        test = false;
        break;
      }
    }
    if (test) ans = 'B';
  }
  cout << ans << ln;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t; cin>>t;
  while(t--) solve();
}