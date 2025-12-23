#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  string s; cin >> s;
  char elem = '2';
  int maxi (0), count(0);
  for (auto i : s) {
    if (i != elem) {
      elem = i;
      count = 1;
      continue;
    }
    count++;
    maxi = count > maxi ? count : maxi;
    if (7 == maxi) {
      cout << "YES" << '\n';
      return 0;
    }
  }
  cout << "NO" << '\n';
  return 0;
}