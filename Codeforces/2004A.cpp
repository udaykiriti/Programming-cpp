#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FOR(i,a,b) for(int i=a;i<b;i++)

void solve(){
  int n; cin >> n;
  vector<int> x(n);
  FOR (i ,0, n) 
    cin >> x[i];
  if (n == 2 && x[0] + 2 <= x[1])
    cout << "YES";
  else
    cout << "NO";
  cout << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}
