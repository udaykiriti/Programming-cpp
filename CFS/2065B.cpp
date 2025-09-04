#include <bits/stdc++.h>
using namespace std;
using i64 = long long int;
using vi  =  vector<int>;

#define ln "\n"
#define stop_sync ios::sync_with_stdio(false)
#define untie_ios cin.tie(nullptr)   
#define sz(x) int((x).size())
#define scanv(x)    \
  for (auto &i : x) \
  cin >> i
#define bug(x) cout << (#x) << ": " << (x) << ln

const int MOD = 1e9 + 7;
const i64 INF = LLONG_MAX;
int main(int argc , char *argv[]) {
  stop_sync; untie_ios;
  int t; cin >> t;
  while (t--) {
    string s; cin >> s;
    int ok = 0;
    for (int i = 0; i < sz(s) - 1; ++i)
      if (s[i] == s[i + 1])
        ok = 1;
    cout << (ok ? 1 : sz(s)) << ln;
  }
  return 0;
}
