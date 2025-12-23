#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define endl '\n'

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int n; cin >> n;
  for (int row = -n; row <= n; ++row)
  {
    int top = n - abs(row);
    for (int i = 0; i < abs(row); ++i)
      cout << "  ";
    for (int i = 0; i < top; ++i)
      cout << i << " ";
    for (int i = top; i > 0; --i)
      cout << i << " ";
    cout << 0 << endl;
  }
  return 0;
}