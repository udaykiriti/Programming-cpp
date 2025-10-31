#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

void solve();

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}

void solve(){
  int n;
  cin >> n;
  if(n <  2) {
    cout << "NO" << '\n';
    return ;
  }

  vector <int> vec(n-2);
  for(int i = 0 ; i < n-2 ; i++){
    if(!(cin >> vec[i]))
      return;
  }

  bool ok = true;
  for(int i = 0 ; i < n-3 ; i++){
    if(vec[i] == 1 && vec[i+1] == 0 && vec[i+2] == 1){
      ok = false;
      break;
    }
  }
  if(ok) cout << "YES" << endl;
  else cout << "NO" << endl;
}
