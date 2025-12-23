#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define debug(n) cout<<(n)<<endl;
const ll INF = 2e18 + 99;
#define ll long long

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t; cin >> t;
  while (t--){
      ll int n, m, x; cin >> n >> m >> x;
      ll a = (x - 1) % n, b = (x - 1) / n;
      cout << a * m + b + 1 << "\n";
  }
  return 0;
}