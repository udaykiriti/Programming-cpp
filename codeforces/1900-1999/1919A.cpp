#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve() {
  ll a, b; cin >> a >> b;
  ll sum = a + b;
  if (sum & 1) cout << "Alice\n";
  else cout << "Bob\n";
}

int main(int argc , char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  ll t(1); cin >> t;
  while (t--) solve();
}
