#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(int argc, char const *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  string s, t; cin >> s >> t;
  int c = 0;
  for (int i = 0; i < t.length(); i++)
    if (s[c] == t[i])
      c++;
  cout << c + 1;
}