#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  string s, s1, s2; cin >> s >> s1;
  int len = s.length();
  for (int i = 0; i < len; i++)
  {
    if (s[i] != s1[i])
      s2 += '1';
    else
      s2 += '0';
  }
  cout << s2;
  return 0;
}