#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n; cin >> n;
  vector<string> bus(n);
  bool found = false;

  for (int i = 0; i < n; i++)
    cin >> bus[i];

  for (int i = 0; i < n; i++) {
    if (!found) {
      if (bus[i][0] == 'O' && bus[i][1] == 'O') {
        bus[i][0] = bus[i][1] = '+';
        found = true;
        break;
      }
      if (bus[i][3] == 'O' && bus[i][4] == 'O') {
        bus[i][3] = bus[i][4] = '+';
        found = true;
        break;
      }
    }
  }

  if (found) {
    cout << "YES" << '\n';
    for (const string &row : bus)
      cout << row << '\n';
  }
  else {
    cout << "NO" << '\n';
  }
  return 0;
}