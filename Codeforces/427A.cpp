#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int n; cin >> n;
  int available_officers = 0;
  int untreated_crimes = 0;
  for (int i = 0; i < n; ++i)
  {
    int event;  cin >> event;
    if (event == -1)
    {
      if (available_officers > 0)
        available_officers--;
      else
        untreated_crimes++;
    }
    else
    {
      available_officers += event;
    }
  }
  cout << untreated_crimes << "\n";
}

int main()
{
  solve();
  return 0;
}