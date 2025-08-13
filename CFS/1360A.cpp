#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int t; cin >> t;
  int a, b, area;
  while (t--)
  {
    cin >> a >> b;
    if (b <= a)
    {
      if (2 * b < a)
        area = a * a;
      else
        area = 4 * b * b;
    }
    else
    {
      if (2 * a < b)
        area = b * b;
      else
        area = 4 * a * a;
    }
    cout << area << endl;
  }
  return 0;
}