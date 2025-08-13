#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(v) (v).begin(), (v).end()
#define FOR(i, n) for (int i = 0; i < (n); ++i)
#define F first
#define S second

int area(int lx, int rx, int ly, int ry)
{
  return (rx - lx + 1) * (ry - ly + 1);
}

void solve(int T)
{
  while (T--)
  {
    int n;
    cin >> n;

    vector<pair<int, int>> pts(n);
    vector<int> xs(n), ys(n);

    FOR(i, n)
    {
      cin >> pts[i].F >> pts[i].S;
      xs[i] = pts[i].F;
      ys[i] = pts[i].S;
    }

    vector<int> sx = xs, sy = ys;
    sort(all(sx));
    sort(all(sy));

    int lx = sx.front(), rx = sx.back();
    int ly = sy.front(), ry = sy.back();
    int cx1 = count(all(xs), lx), cx2 = count(all(xs), rx);
    int cy1 = count(all(ys), ly), cy2 = count(all(ys), ry);

    int nx1 = (cx1 < n) ? sx[cx1] : lx;
    int nx2 = (cx2 < n) ? sx[n - 1 - cx2] : rx;
    int ny1 = (cy1 < n) ? sy[cy1] : ly;
    int ny2 = (cy2 < n) ? sy[n - 1 - cy2] : ry;

    int a0 = area(lx, rx, ly, ry);
    int res = numeric_limits<int>::max();

    FOR(i, n)
    {
      int xi = pts[i].first, yi = pts[i].second;

      int clx = (xi != lx || cx1 > 1) ? lx : nx1;
      int crx = (xi != rx || cx2 > 1) ? rx : nx2;
      int cly = (yi != ly || cy1 > 1) ? ly : ny1;
      int cry = (yi != ry || cy2 > 1) ? ry : ny2;

      int dx = crx - clx + 1;
      int dy = cry - cly + 1;
      int a1 = dx * dy;

      if (a1 > n - 1)
        res = min(res, a1);
      else
        res = min(res, min((dx + 1) * dy, dx * (dy + 1)));
    }

    cout << min(a0, res) << endl;
  }
}

int main()
{
  int t;
  cin >> t;
  solve(t);
  return 0;
}
