#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PRINT4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl
#define PRINT1(x) cout << x << endl

int main()
{
  ll x1, x2, x3, x4, y1, y2, y3, y4, dx, dy;
  while (cin >> x1 >> y1 >> x2 >> y2)
  {
    dx = abs(x1 - x2);
    dy = abs(y1 - y2);

    if (dx == dy)
    {
      PRINT4(x1, y2, x2, y1);
    }
    else if (x1 == x2)
    {
      x3 = x4 = x1 + abs(y1 - y2);
      y3 = y1;
      y4 = y2;
      PRINT4(x3, y3, x4, y4);
    }
    else if (y1 == y2)
    {
      y3 = y4 = y1 + abs(x1 - x2);
      x3 = x1;
      x4 = x2;
      PRINT4(x3, y3, x4, y4);
    }
    else
    {
      cout<<-1;
    }
  }
  return 0;
}