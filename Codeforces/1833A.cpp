#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

void solve(){
  int n; string s; cin >> n >> s;
  map<string, int> mp;
  for (int i = 0; i < n - 1; i++){
    string t;
    t.push_back(s[i]);
    t.push_back(s[i + 1]);
    mp[t]++;
  }
  cout << (int)mp.size() << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1; cin >> t;
  while (t--) solve();
}