#include <bits/stdc++.h>
using namespace std;

bool form_rectangle(int a, int b, int c)
{
  int sticks[3] = {a, b, c};
  sort(sticks, sticks + 3);
  if ((sticks[0] == sticks[1] && sticks[2] % 2 == 0) ||(sticks[1] == sticks[2] && sticks[0] % 2 == 0))
    return true;
  if (sticks[0] + sticks[1] == sticks[2])
    return true;
  return false;
}

int main()
{
  int t; cin >> t;
  while (t--)
  {
    int l1, l2, l3; cin >> l1 >> l2 >> l3;
    cout << (form_rectangle(l1, l2, l3) ? "YES" : "NO") << '\n';
  }
  return 0;
}