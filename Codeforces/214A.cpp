#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int n, m; cin >> n >> m;
  int count = 0;
  for (int a = 0; a <= 31; ++a)
    for (int b = 0; b <= 31; ++b)
      if (a * a + b == n && a + b * b == m)
        count++;
  cout << count << endl;
  return 0;
}
