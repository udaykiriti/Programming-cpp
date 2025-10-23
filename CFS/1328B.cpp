#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  ll n,k; cin >> n >> k;
  int pos1 = 0, pos2 = 0;
  for (int i = 1; i <= n; ++i) {
    ll total = i * (i - 1LL) / 2;
    if (total >= k) {
      pos1 = i;
      break;
    }
  }

  ll Tb = (pos1 - 1LL) * (pos1 - 2) / 2;
  ll offset = k - Tb - 1;

  int ind1 = n - pos1;
  int ind2 = n - offset - 1;

  string result(n, 'a');
  result[ind1] = 'b';
  result[ind2] = 'b';
  cout << result << endl;
}

int main(int argc , char *argv[]) {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int t(1),tcase(0); cin >> t;
  while (++tcase,t--) solve();
  return 0;
}