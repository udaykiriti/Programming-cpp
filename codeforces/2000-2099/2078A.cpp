#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FOR(i,a,b) for(int i=(a);i<(b);i++)

void solve(){
  int n,x; cin >> n >> x; 
  vector<int> a(n);
  int total_sum = 0;
  
  FOR(i,0,n) {
      cin >> a[i];
      total_sum += a[i];
  }

  if (total_sum == x * n) cout << "YES" << endl;
  else cout << "NO" << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t; cin>>t;
  while (t--) solve();
  return 0;
}