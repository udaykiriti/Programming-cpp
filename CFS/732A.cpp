#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int k, r; cin >> k >> r;
  for (int i = 1; i <= 10; i++)
  {
    int total = i * k;
    if (total % 10 == 0 || total % 10 == r)
    {
      cout << i << endl;
      break;
    }
  }
  return 0;
}