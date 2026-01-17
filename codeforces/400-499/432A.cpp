#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(x) cout << (x) << endl;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n, k; cin >> n >> k;
  int c = 0;
  for (int i = 0; i < n; ++i)
  {
    int p; cin >> p;
    if (p <= 5 - k)
      c++;
  }
  cout << c / 3 << endl;
  return 0;
}