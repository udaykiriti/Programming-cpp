#include <bits/stdc++.h>
using namespace std;

bool pwd(const string &s)
{
  char last_digit = '0' - 1;
  char last_letter = 'a' - 1;
  bool letter_seen = false;

  for (char c : s)
  {
    if (isdigit(c))
    {
      if (letter_seen)
        return false;
      if (c < last_digit)
        return false;
      last_digit = c;
    }
    else
    {
      letter_seen = true;
      if (c < last_letter)
        return false;
      last_letter = c;
    }
  }
  return true;
}

int main()
{
  int t; cin >> t;
  while (t--)
  {
    int n; string s; cin >> n >> s;
    cout << (pwd(s) ? "YES" : "NO") << '\n';
  }
  return 0;
}