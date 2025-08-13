#include <bits/stdc++.h>
using namespace std;

bool isMeow(string s)
{
  string t = "";
  for (int i = 0; i < s.length(); ++i)
  {
    s[i] = tolower(s[i]);
    if (t.empty() || s[i] != t.back())
      t += s[i];
  }

  return t == "meow";
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t; cin >> t;
  while (t--)
  {
    int n; string s;cin >> n >> s;
    cout << (isMeow(s) ? "YES" : "NO") << endl;
  }
  return 0;
}
