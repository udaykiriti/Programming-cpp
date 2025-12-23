#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long


int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int t; cin >> t;
  while (t--)
  {
    int x, k;  cin >> x >> k;
    if (abs(x) % k != 0)
    {
      cout << "1" << endl;
      cout << x << endl;
    }
    else
    {
      cout << "2" << endl;
      cout << (k + 1) << " " << (x - k - 1) << endl;
    }
  }
  return 0;
}