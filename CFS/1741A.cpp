#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(nullptr);

  int t; cin >> t;
  while (t--) {
    string s1, s2; cin >> s1 >> s2;

    int len1 = s1.length();
    int len2 = s2.length();

    char c1 = s1[len1 - 1];
    char c2 = s2[len2 - 1];

    if (s1 == s2) {
      cout << "=\n";
      continue;
    }

    bool result = len1 > len2;

    if (c1 == c2 && c1 == 'S') result = !result;
    else if (c1 != c2) result = c1 < c2;

    cout << (result ? ">" : "<") << '\n';
  }
  return 0;
}
