#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(NULL);
  string x; cin >> x;

  for (int i = 0; i < x.size(); ++i)
  {
    int digit = x[i] - '0';
    if (i == 0 && digit == 9)
      continue;
    if (digit > 4)
      x[i] = '0' + (9 - digit);
  }

  cout << x << '\n';
  return 0;
}