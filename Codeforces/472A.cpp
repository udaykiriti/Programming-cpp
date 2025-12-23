#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

bool is_composite(int x)
{
  if (x <= 1) return false;
  for (int i = 2; i * i <= x; i++)
    if (x % i == 0) return true;
  return false;
}

void solve(int n)
{
  for (int x = 4; x <= n / 2; x++)
  {
    int y = n - x;
    if (is_composite(x) && is_composite(y))
    {
      cout << x << " " << y << endl;
      return;
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n; cin >> n;
  solve(n);
  return 0;
}