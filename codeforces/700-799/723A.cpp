#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(0);
  int a, b, c; cin >> a >> b >> c;
  int x[] = {a, b, c};
  sort(x, x + 3);
  cout << (x[2] - x[0]) << endl;
  return 0;
}