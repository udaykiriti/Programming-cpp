#include <bits/stdc++.h>
using namespace std;

void solve(){
  string n; cin >> n;
  if ((n.back() - '0') % 2 == 0){
    cout << 0 << endl;
    return;
  }
  
  if ((n[0] - '0') % 2 == 0){
    cout << 1 << endl;
    return;
  }
  
  for (int i = 1; i < n.size() - 1; i++){
    if ((n[i] - '0') % 2 == 0) {
      cout << 2 << endl;
      return;
    }
  }
  cout << -1 << endl;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);  
  int t;  cin >> t;  
  while (t--)  solve();
  return 0;
}
