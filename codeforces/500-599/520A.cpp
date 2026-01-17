#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n;
  string s; cin >> n >> s;
  set<char> letters;
  for (char c : s)
    letters.insert(tolower(c));

  if (letters.size() == 26) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}