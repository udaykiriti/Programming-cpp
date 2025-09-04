#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define GG return 0
#define FOR(i, a, b) for (int i = a; i < b; i++)

void solve() {
  int n, freqSum = 0; cin >> n;
  FOR(i, 0, n - 1) {
    int freq; cin >> freq;
    freqSum += freq;
  }
  cout << freqSum * (-1) << endl;
}

int main(int argc , char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t; cin >> t;
  while (t--) solve();
  GG;
}
